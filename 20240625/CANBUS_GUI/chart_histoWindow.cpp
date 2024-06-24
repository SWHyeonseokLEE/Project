#include "chart_histoWindow.h"

ChartDialog::ChartDialog(QWidget *parent)
    : QDialog(parent), cnt_TPS(0), cnt_RPM(0), cnt_VS(0), cnt_TEMP_ENG(0), cnt_SAS_Angle(0), tm_cnt(0), flag_autoscale(0)
{
    setupLayout();
    setupPlots();
    setupConnections();
    initializeTimer();
}

ChartDialog::~ChartDialog()
{
}

void ChartDialog::setupLayout()
{
    layout_y = new QVBoxLayout(this);
    layout_x = new QHBoxLayout(this);
    layout_x1 = new QHBoxLayout(this);
    layout_x2 = new QHBoxLayout(this);
    layout_x3 = new QHBoxLayout(this);

    layout_y->addLayout(layout_x3);
    layout_y->addLayout(layout_x2);
    layout_y->addLayout(layout_x);
    layout_y->addLayout(layout_x1);

    QCheckBox* checkBox = new QCheckBox("AutoScale Check Box", this);
    checkBox->setChecked(false);
    layout_x3->addWidget(checkBox);
    connect(checkBox, &QCheckBox::toggled, this, &ChartDialog::onCheckBoxToggled);

    QCheckBox* cb_histogram = new QCheckBox("Histogram On", this);
    cb_histogram->setChecked(false);
    layout_x3->addWidget(cb_histogram);
    connect(cb_histogram, &QCheckBox::toggled, this, &ChartDialog::onCb_histogramToggled);

    for (int i = 0; i < 5; ++i)
    {
        layout_state[i] = new QVBoxLayout(this);
        addInputField(layout_state[i], "plot y Value Range", lineEdit_range_y[i]);
        addInputField(layout_state[i], "plot x Time Range", lineEdit_range_x[i]);
        addInputField(layout_state[i], "warning Range", lineEdit_warning[i]);
        addInputField(layout_state[i], "histogram Range", lineEdit_histogram[i], "0");
        layout_x2->addLayout(layout_state[i]);
    }
}

void ChartDialog::setupPlots()
{
    for (int i = 0; i < 5; ++i)
    {
        plots[i] = createPlot(i, plot_name[i], plot_axis[i], plot_axis[5]);
        layout_x->addWidget(plots[i]);

        raw_data[i] = new QVector<double>();
        plots_b[i] = createHistogramPlot(i, plot_axis[i], plot_axis[6], bins[i], bar_data[i], histogram[i]);
        layout_x1->addWidget(plots_b[i]);
    }
}

void ChartDialog::setupConnections()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ChartDialog::updateChart);
}

void ChartDialog::initializeTimer()
{
    timer->start(500);
}

void ChartDialog::addInputField(QVBoxLayout* layout, const QString& label, QLineEdit*& lineEdit, const QString& defaultValue)
{
    layout->addWidget(new QLabel(label, this));
    lineEdit = new QLineEdit(this);
    lineEdit->setText(defaultValue);
    layout->addWidget(lineEdit);
}

QCustomPlot* ChartDialog::createPlot(int index, const QString& name, const QString& yAxisLabel, const QString& xAxisLabel)
{
    QCustomPlot* plot = new QCustomPlot();
    plot->addGraph();
    plot->graph(0)->setName(name);
    plot->yAxis->setLabel(yAxisLabel);
    plot->xAxis->setLabel(xAxisLabel);
    plot->legend->setVisible(true);
    plot->setFixedSize(400, 300);
    plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    rect_warning[index] = new QCPItemRect(plot);
    rect_warning[index]->topLeft->setCoords(0, 0);
    rect_warning[index]->bottomRight->setCoords(0, 0);
    rect_warning[index]->setBrush(QBrush(QColor(0, 255, 0, 50)));
    return plot;
}

QCustomPlot* ChartDialog::createHistogramPlot(int index, const QString& xAxisLabel, const QString& yAxisLabel, QVector<double>*& bins, QVector<double>*& barData, QCPBars*& histogram)
{
    QCustomPlot* plot = new QCustomPlot();
    plot->setFixedSize(400, 300);
    plot->xAxis->setLabel(xAxisLabel);
    plot->yAxis->setLabel(yAxisLabel);
    bins = new QVector<double>();
    barData = new QVector<double>();
    histogram = new QCPBars(plot->xAxis, plot->yAxis);
    histogram->setData(*bins, *barData);
    plot->rescaleAxes();
    return plot;
}

void ChartDialog::onCheckBoxToggled(bool checked)
{
    flag_autoscale = checked ? 1 : 0;
    QMessageBox::information(this, "AutoScale", checked ? "AutoScale Off." : "AutoScale On.");
    for (int i = 0; i < 5; ++i)
    {
        if (checked)
        {
            parseRange(lineEdit_range_x[i]->text(), range_min[i].setX, range_max[i].setX);
            parseRange(lineEdit_range_y[i]->text(), range_min[i].setY, range_max[i].setY);
            parseRange(lineEdit_warning[i]->text(), range_warning[i].setX, range_warning[i].setY);
        }
        else
        {
            resetRanges(i);
        }
    }
}

void ChartDialog::onCb_histogramToggled(bool checked)
{
    flag_autoscale = checked ? 1 : 0;
    QMessageBox::information(this, "Histogram", checked ? "Histogram On." : "Histogram Off.");
    for (int i = 0; i < 5; ++i)
    {
        if (checked)
        {
            histogram_binsize[i] = lineEdit_histogram[i]->text().toInt();
        }
        else
        {
            resetHistogram(i);
        }
    }
}

void ChartDialog::resetRanges(int index)
{
    range_min[index] = QPointF(0, 0);
    range_max[index] = QPointF(0, 0);
    range_warning[index] = QPointF(0, 0);
    rect_warning[index]->topLeft->setCoords(0, 0);
    rect_warning[index]->bottomRight->setCoords(0, 0);
}

void ChartDialog::resetHistogram(int index)
{
    histogram_binsize[index] = 0;
    bins[index]->clear();
    bar_data[index]->clear();
}

void ChartDialog::parseRange(const QString& text, const std::function<void(double)>& setMin, const std::function<void(double)>& setMax)
{
    if (text.contains(","))
    {
        QStringList parts = text.split(',', Qt::SkipEmptyParts);
        setMin(parts[0].toDouble());
        setMax(parts[1].toDouble());
    }
}

void ChartDialog::appendData(int index, double value)
{
    if (value != 7777 && plots[index] != nullptr && raw_data[index] != nullptr)
    {
        plots[index]->graph(0)->addData(index == 0 ? cnt_TPS++ : index == 1 ? cnt_RPM++ : index == 2 ? cnt_VS++ : index == 3 ? cnt_TEMP_ENG++ : cnt_SAS_Angle++, value);
        raw_data[index]->append(value);
        if (value < range_warning[index].x() || value > range_warning[index].y())
        {
            flag_warn[index] = 1;
        }
    }
}

void ChartDialog::appendTPS(double value) { appendData(0, value); }
void ChartDialog::appendRPM(double value) { appendData(1, value); }
void ChartDialog::appendVS(double value) { appendData(2, value); }
void ChartDialog::appendTEMPENG(double value) { appendData(3, value); }
void ChartDialog::appendSASANGLE(double value) { appendData(4, value); }

void ChartDialog::updateChart()
{
    ++tm_cnt;
    qDebug() << tm_cnt;

    if (!flag_autoscale)
    {
        for (auto* plot : plots)
        {
            plot->rescaleAxes();
            plot->replot();
        }
    }
    else
    {
        for (int i = 0; i < 5; ++i)
        {
            updatePlot(i);
        }
    }

    if (tm_cnt % 2 == 0)
    {
        for (int i = 0; i < 5; ++i)
        {
            replotHistogram(i);
        }
    }
}

void ChartDialog::updatePlot(int index)
{
    if (range_max[index].x() != 0)
    {
        plots[index]->xAxis->setRange(range_min[index].x(), range_max[index].x());
        rect_warning[index]->topLeft->setCoords(range_min[index].x(), range_warning[index].y());
        rect_warning[index]->bottomRight->setCoords(range_max[index].x(), range_warning[index].x());
        rect_warning[index]->setBrush(QBrush(QColor(0, 255, 0, 80)));
    }
    else
    {
        plots[index]->rescaleAxes();
        rect_warning[index]->topLeft->setCoords(0, range_warning[index].y());
        rect_warning[index]->bottomRight->setCoords(plots[index]->xAxis->range().upper, range_warning[index].x());
        rect_warning[index]->setBrush(QBrush(QColor(0, 255, 0, 80)));
    }

    if (range_warning[index].y() != 0 && flag_warn[index])
    {
        plots[index]->axisRect()->setBackground(QBrush(QColor(255, 0, 0, 50)));
        flag_warn[index] = 0;
    }
    else
    {
        plots[index]->axisRect()->setBackground(QBrush(QColor(255, 255, 255)));
    }

    plots[index]->yAxis->setRange(range_min[index].y(), range_max[index].y());
    plots[index]->replot();
}

void ChartDialog::replotHistogram(int index)
{
    replotBar(histogram_binsize[index], plots_b[index], histogram[index], raw_data[index], bins[index], bar_data[index]);
}

void ChartDialog::replotBar(int binSize, QCustomPlot* plot, QCPBars* histogram, QVector<double>* rawData, QVector<double>* category, QVector<double>* dataCount)
{
    category->clear();
    dataCount->clear();

    double maxValue = *std::max_element(rawData->begin(), rawData->end());
    double minValue = *std::min_element(rawData->begin(), rawData->end());

    binSize = (binSize == 0) ? calculateBinSize(minValue, maxValue) : binSize;
    int numBinsBelowZero = std::abs(minValue) / binSize + 1;
    int numBinsAboveZero = maxValue / binSize + 1;

    QVector<int> binCounts(numBinsBelowZero + numBinsAboveZero, 0);
    calculateBinCounts(rawData, binCounts, binSize, numBinsBelowZero);

    populateHistogramData(numBinsBelowZero, numBinsAboveZero, binCounts, category, dataCount, binSize);
    histogram->setData(*category, *dataCount);
    plot->rescaleAxes();
    plot->xAxis->setRange(minValue - binSize, maxValue + binSize);
    plot->replot();
}

int ChartDialog::calculateBinSize(double minValue, double maxValue)
{
    if (maxValue >= 700 || minValue <= -700)
    {
        return 100;
    }
    if (maxValue <= 100 || minValue >= -100)
    {
        return 5;
    }
    return 50;
}

void ChartDialog::calculateBinCounts(const QVector<double>* rawData, QVector<int>& binCounts, int binSize, int numBinsBelowZero)
{
    for (double value : *rawData)
    {
        int binIndex = (value < 0) ? numBinsBelowZero + (value / binSize) : numBinsBelowZero + (value / binSize);
        if (binIndex >= 0 && binIndex < binCounts.size())
        {
            binCounts[binIndex]++;
        }
    }
}

void ChartDialog::populateHistogramData(int numBinsBelowZero, int numBinsAboveZero, const QVector<int>& binCounts, QVector<double>* category, QVector<double>* dataCount, int binSize)
{
    for (int i = 0; i < numBinsBelowZero; ++i)
    {
        category->append(-(numBinsBelowZero - i) * binSize);
        dataCount->append(binCounts[i]);
    }
    for (int i = numBinsBelowZero; i < numBinsBelowZero + numBinsAboveZero; ++i)
    {
        category->append((i - numBinsBelowZero) * binSize);
        dataCount->append(binCounts[i]);
    }
}

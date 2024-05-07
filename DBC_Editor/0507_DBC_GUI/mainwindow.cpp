#include "mainwindow.h"
#include "./ui_mainwindow.h"


QString g_msg_dbc="";
int g_msg_cnt=0;
int g_sg_cnt[100]={0,};

//ChartDialog *chartDialog=nullptr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    tcpServer(nullptr),
    clientSocket(nullptr),
    chartDialog(nullptr)

{
    ui->setupUi(this);
    g_sg_cnt[0]=1;

    tcpServer = new QTcpServer(this);
    if(tcpServer->listen(QHostAddress::Any, 12345)) {
        connect(tcpServer, &QTcpServer::newConnection, this, &MainWindow::on_NewConnection);
    }

    ui->txt_DBCfilepath->setText("");

    ui->NUM_TPS->setDigitCount(6);
    ui->NUM_RPM->setDigitCount(6);
    ui->NUM_VS->setDigitCount(6);
    ui->NUM_TEMP_ENG->setDigitCount(6);
    ui->NUM_SAS_Angle->setDigitCount(6);
    chart_on_flag=0;
}

MainWindow::~MainWindow()
{
    tcpServer->close();
    delete ui;
}

void MainWindow::on_bt_msg_clicked()
{
    QString CAN_id = ui->ccc->toPlainText();
    QString msg_name = ui->msg_name->toPlainText();
    QString msg_len = QString::number(ui->msg_length->value());
    QString msg_cm = ui->msg_cm->toPlainText();


    if(!CAN_id.isEmpty() && !msg_name.isEmpty() && !msg_len.isEmpty() && g_sg_cnt[g_msg_cnt] != 0)
    {
        g_msg_cnt++;
        QString msg_text = QString("BO_ %1 %2: %3 %4").arg(CAN_id, msg_name, msg_len, msg_cm);
        g_msg_dbc += !g_msg_dbc.isEmpty() ? "\n" + msg_text : msg_text;
    }

    ui->DBC_temp->setText(g_msg_dbc);
    ui->DBC_temp->verticalScrollBar()->setValue(ui->DBC_temp->verticalScrollBar()->maximum());
}

void MainWindow::on_bt_signal_clicked()
{
    QString sg_name= ui->sg_name->toPlainText();
    QString sg_start = QString::number(ui->sg_start->value());
    QString sg_len = QString::number(ui->sg_length->value());
    QString sg_endian= ui->sg_endian->currentText();
    QString sg_type= ui->sg_type->currentText();
    QString sg_factor= ui->sg_factor->toPlainText();
    QString sg_offset= ui->sg_offset->toPlainText();
    QString sg_min= ui->sg_min->toPlainText();
    QString sg_max= ui->sg_max->toPlainText();
    QString sg_unit= ui->sg_unit->toPlainText();
    QString sg_cm= ui->sg_cm->toPlainText();

    if(!sg_name.isEmpty() && !sg_factor.isEmpty() && !sg_offset.isEmpty() && !sg_min.isEmpty() && !sg_max.isEmpty() && !sg_unit.isEmpty() && g_msg_cnt > 0)
    {
        if(sg_endian == "Little")
        {
            sg_endian ="@1";
        }
        else
        {
            sg_endian ="@0";
        }

        if(sg_type == "Signed")
        {
            sg_type ="-";
        }
        else
        {
            sg_type ="+";
        }

        g_sg_cnt[g_msg_cnt]++;
        QString sg_text = "\n SG_ "+
                          sg_name + " : " +
                          sg_start + "|" +
                          sg_len +
                          sg_endian +
                          sg_type + " (" +
                          sg_factor + ","+
                          sg_offset + ") ["+
                          sg_min + "|"+
                          sg_max + "] \"" +
                          sg_cm + "\"";

        g_msg_dbc = g_msg_dbc + sg_text;
    }

    ui->DBC_temp->setText(g_msg_dbc);
    ui->DBC_temp->verticalScrollBar()->setValue(ui->DBC_temp->verticalScrollBar()->maximum());
}

void MainWindow::on_bt_del_lastline_clicked()
{
    if (!g_msg_dbc.isEmpty())
    {
        int lastline_index = g_msg_dbc.lastIndexOf("\n");
        g_msg_dbc = lastline_index != -1 ? g_msg_dbc.left(lastline_index) : "";
        g_sg_cnt[g_msg_cnt] == 0 ? g_msg_cnt-- : g_sg_cnt[g_msg_cnt]--;
    }

    ui->DBC_temp->setText(g_msg_dbc);
    ui->DBC_temp->verticalScrollBar()->setValue(ui->DBC_temp->verticalScrollBar()->maximum());
}

void MainWindow::on_bt_save_clicked()
{
    if(g_sg_cnt[g_msg_cnt] != 0 && g_msg_cnt > 0)
    {
        QString file_path = QFileDialog::getSaveFileName(this, tr("Save DBC File"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("DBC Files (*.dbc);;All Files (*)"));
        if (!file_path.isEmpty()) {
            QFile file(file_path);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&file);
                file.close();
            }
        }
    }
}


void MainWindow::on_bt_addDBC_clicked()
{
    if(g_sg_cnt[g_msg_cnt] != 0 && g_msg_cnt > 0)
    {
        QString file_path = QFileDialog::getOpenFileName(this, tr("Open DBC File"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("DBC Files (*.dbc);;All Files (*)"));
        if (!file_path.isEmpty())
        {
            QFile file(file_path);
            if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
            {
                QTextStream out(&file);
                out.seek(file.size());
                out << "\n" << g_msg_dbc;
                file.close();
            }
        }
    }
}




QVector<Message> messages ;

void MainWindow::on_bt_OpenDBC_clicked()
{
    QString str_caption = "Open File";
    QString str_dir     = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString str_filters = "DBC files (*.dbc);; All Files (*.*)";
    // 파일 저장할 폴더 경로 가져오기
    QString filePathDBC = QFileDialog::getOpenFileName(this, str_caption, str_dir, str_filters);
    QFile fileDBC(filePathDBC);
    if(fileDBC.exists())
    {
        messages = DBCParse::parseDBCToMessages(filePathDBC);
        std::sort(messages.begin(), messages.end(), [](const Message &m1, const Message &m2) { return m1.id < m2.id; });
        ui->txt_DBCfilepath->setText(filePathDBC);
        ui->sg_select_combo->clear();

        ui->msg_table->setColumnCount(3);
        ui->msg_table->setHorizontalHeaderLabels(QStringList() << "Name" << "ID" << "Data Length");

        for(int i = 0; i < messages.size(); ++i)
        {
            ui->sg_select_combo->addItem(QString::number(messages[i].id));
            ui->sg_select_combo_2->addItem(QString::number(messages[i].id));

            int rowCount = ui->msg_table->rowCount();
            ui->msg_table->insertRow(rowCount);
            ui->msg_table->setItem(rowCount, 0, new QTableWidgetItem(messages[i].name));
            ui->msg_table->setItem(rowCount, 1, new QTableWidgetItem(QString::number(messages[i].id)));
            ui->msg_table->setItem(rowCount, 2, new QTableWidgetItem(QString::number(messages[i].dl)));
        }

        ui->msg_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->msg_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

}

void MainWindow::on_sg_select_combo_currentIndexChanged(int index)
{
    if (index >= 0 && index < messages.size())
    {
        const QVector<Signal> &signalList = messages[index].signalList;

        // 시그널 테이블 모델 초기화
        ui->sg_table->setColumnCount(9);
        ui->sg_table->setRowCount(0);
        ui->sg_table->setHorizontalHeaderLabels(QStringList() << "Name" << "Start Bit" << "Length" << "Endian" << "Scale" << "Offset" << "Min" << "Max" << "Unit");

        // 시그널 테이블에 데이터 추가
        for (int i = 0; i < signalList.size(); ++i) {
            const Signal &signal = signalList[i];
            // 행 추가
            int rowCount = ui->sg_table->rowCount();
            ui->sg_table->insertRow(rowCount);
            ui->sg_table->setItem(rowCount, 0, new QTableWidgetItem(signal.name));
            ui->sg_table->setItem(rowCount, 1, new QTableWidgetItem(QString::number(signal.startBit)));
            ui->sg_table->setItem(rowCount, 2, new QTableWidgetItem(QString::number(signal.bitLength)));
            ui->sg_table->setItem(rowCount, 3, new QTableWidgetItem(signal.endian));
            ui->sg_table->setItem(rowCount, 4, new QTableWidgetItem(QString::number(signal.scale)));
            ui->sg_table->setItem(rowCount, 5, new QTableWidgetItem(QString::number(signal.offset)));
            ui->sg_table->setItem(rowCount, 6, new QTableWidgetItem(QString::number(signal.min)));
            ui->sg_table->setItem(rowCount, 7, new QTableWidgetItem(QString::number(signal.max)));
            ui->sg_table->setItem(rowCount, 8, new QTableWidgetItem(signal.unit));
        }

        // 시그널 테이블 모델 설정

        ui->sg_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->sg_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}
int live_end_flag=0;
void MainWindow::on_pushButton_mode1_clicked()
{
    if(live_end_flag ==1 && messages.size() > 0)
    {
        ui->live_table->setRowCount(0);
        ui->live_table->setColumnCount(messages[ui->sg_select_combo_2->currentIndex()].signalList.size());

        QStringList headerLabels;
        for (const Signal &signal : messages[ui->sg_select_combo_2->currentIndex()].signalList) {
            headerLabels <<signal.name;
        }
        ui->live_table->setHorizontalHeaderLabels(headerLabels);
        ui->live_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        if(ui->live_table->rowCount()==0){
            ui->live_table->insertRow(0);
        }
        ui->live_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        live_end_flag=2;
    }else{
    }
}

void MainWindow::on_pushButton_mode2_clicked()
{
    if(live_end_flag ==1 && messages.size() > 0)
    {
        ui->live_table->setRowCount(0);
        ui->live_table->setColumnCount(5);

        QStringList headerLabels;

        headerLabels << "쓰로틀 퍼센트"<<"RPM"<<"속도"<<"엔진 온도"<<"스티어 각도";

        ui->live_table->setHorizontalHeaderLabels(headerLabels);
        ui->live_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        if(ui->live_table->rowCount()==0)
        {
            ui->live_table->insertRow(0);
        }
        ui->live_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        live_end_flag=3;
    }
    else{

    }
}


void MainWindow::on_pushButton_close_clicked()
{
    if(live_end_flag >1){
        ui->live_table->clear();
        ui->live_table->setRowCount(0);
        ui->live_table->setColumnCount(0);

        live_end_flag=1;

        return;
    }
}


void MainWindow::on_bt_Clear_clicked()
{
    messages.clear();
    ui->txt_DBCfilepath->clear();
    ui->live_table->clear();
    ui->live_table->setColumnCount(0);
    ui->live_table->setRowCount(0);
    ui->sg_select_combo->clear();
    ui->sg_select_combo_2->clear();
    ui->msg_table->clear();
    ui->msg_table->setColumnCount(0);
    ui->msg_table->setRowCount(0);
    ui->sg_table->clear();
    ui->sg_table->setColumnCount(0);
    ui->sg_table->setRowCount(0);

}


void MainWindow::on_NewConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &MainWindow::on_ReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);

    live_end_flag=1;
}
#define MASK64(nbits) ((0xffffffffffffffff)>> (64-nbits))
double MainWindow::dcodeMsgSg(int msg_id, const char* sg_name, const QString& _data, QLCDNumber* lcd){//,QLineSeries *series){//int colindex){
    QStringList parts = _data.split(' ',Qt::SkipEmptyParts);
    int ID= parts[0].toInt(nullptr,16);
    if(ID != msg_id){
        return 7777;
    }
    int length=parts[1].toInt();
    uint8_t data[8]= {0,};
    for (int i = 0; i < length; ++i) {

        data[i] = parts[2 + i].toInt(nullptr, 16);
    }
    int msg_address=-1;
    for(int i=0;i<messages.size();i++){
        if(messages[i].id==msg_id)msg_address=i;
    }
    if(msg_address<0)return 7777;
    int sg_address=-1;
    for(int i=0;i<messages[msg_address].signalList.size();i++){
        if(messages[msg_address].signalList[i].name==sg_name)sg_address=i;
    }
    if(sg_address<0)return 7777;
    const Signal &signal = messages[msg_address].signalList[sg_address];
    uint8_t start_byte =signal.startBit / 8;
    uint8_t startbit_in_byte=signal.startBit % 8;
    uint8_t end_byte = 0;
    int8_t count = 0;
    uint64_t target = data[start_byte] >> startbit_in_byte;
    uint8_t current_target_length = (8-startbit_in_byte);
    if(signal.endian == "Big") // Motorola (big endian)
    {
        end_byte = (start_byte * 8 + 8 - startbit_in_byte - signal.bitLength) / 8;

        for(count = start_byte-1; count >= end_byte; count --)
        {
            target |= data[count] << current_target_length;
            current_target_length += 8;
        }
    }
    else // Intel (little endian)
    {
        end_byte = (signal.startBit+signal.bitLength) / 8;

        for(count = start_byte+1; count < end_byte; count ++)
        {
            target |= data[count] << current_target_length;
            current_target_length += 8;
        }
    }

    target &= MASK64(signal.bitLength);
    double scaledValue = ( (int64_t) target ) * signal.scale + signal.offset;
    if(strcmp(sg_name, "TPS") == 0 && scaledValue <=0.5f)scaledValue=0;
    else if(strcmp(sg_name, "SAS_Angle") == 0 && scaledValue >=600)scaledValue-=6553.5f;
    QString val_str = QString::number(scaledValue, 'f', 1);
    lcd->display(scaledValue);
    return scaledValue;
}
void MainWindow::decodeCan(QString _data){

        QStringList parts = _data.split(' ',Qt::SkipEmptyParts);
        int ID= parts[0].toInt(nullptr,16);
        if(ID != messages[ui->sg_select_combo_2->currentIndex()].id){
            return;
        }
        int length=parts[1].toInt();
        uint8_t data[8]= {0,};

        for (int i = 0; i < length; ++i) {
            data[i] = parts[2 + i].toInt(nullptr, 16);
        }

        QVector<QVariant> rowData;
        for (const Signal &signal : messages[ui->sg_select_combo_2->currentIndex()].signalList)
        {
            uint8_t start_byte =signal.startBit / 8;
            uint8_t startbit_in_byte=signal.startBit % 8;
            uint8_t end_byte = 0;
            int8_t count = 0;
            uint64_t target = data[start_byte] >> startbit_in_byte;
            uint8_t current_target_length = (8-startbit_in_byte);
            if(signal.endian == "Big") // Motorola (big endian)
            {
                end_byte = (start_byte * 8 + 8 - startbit_in_byte - signal.bitLength) / 8;

                for(count = start_byte-1; count >= end_byte; count --)
                {
                    target |= data[count] << current_target_length;
                    current_target_length += 8;
                }
            }
            else // Intel (little endian)
            {
                end_byte = (signal.startBit+signal.bitLength) / 8;

                for(count = start_byte+1; count < end_byte; count ++)
                {
                    target |= data[count] << current_target_length;
                    current_target_length += 8;
                }
            }

            target &= MASK64(signal.bitLength);
            double scaledValue = ( (int64_t) target ) * signal.scale + signal.offset;
            rowData.append(scaledValue);
            for (int colIndex = 0; colIndex < rowData.size(); ++colIndex)
            {
                QTableWidgetItem *item = new QTableWidgetItem(rowData.at(colIndex).toString());
                ui->live_table->setItem(0, colIndex, item);
            }
        }
}

void MainWindow::on_ReadyRead()
{
    QByteArray data = clientSocket->readAll();
    if(live_end_flag ==2)
    {
        //qDebug() << "Received:" << QString(data);
        decodeCan(data);
    }
    else if(live_end_flag == 3 && chart_on_flag == 1)
    {
        //qDebug() << "Received:" << QString(data);
        chartDialog->appendTPS(dcodeMsgSg(809,"TPS",data,ui->NUM_TPS));
        chartDialog->appendRPM(dcodeMsgSg(790,"N",data,ui->NUM_RPM));
        chartDialog->appendVS(dcodeMsgSg(790,"VS",data,ui->NUM_VS));
        chartDialog->appendTEMPENG(dcodeMsgSg(809,"TEMP_ENG",data,ui->NUM_TEMP_ENG));
        chartDialog->appendSASANGLE(dcodeMsgSg(688,"SAS_Angle",data,ui->NUM_SAS_Angle));
    }
    else if(live_end_flag == 3)
    {
        //qDebug() << "Received:" << QString(data);
        dcodeMsgSg(809,"TPS",data,ui->NUM_TPS);
        dcodeMsgSg(790,"N",data,ui->NUM_RPM);
        dcodeMsgSg(790,"VS",data,ui->NUM_VS);
        dcodeMsgSg(809,"TEMP_ENG",data,ui->NUM_TEMP_ENG);
        dcodeMsgSg(688,"SAS_Angle",data,ui->NUM_SAS_Angle);
    }

    ui->txt_t3->setText(QString(data));
}


void MainWindow::on_bt_chart_clicked()
{
    if (!chartDialog)
    {
        chart_on_flag=1;
        chartDialog = new ChartDialog(this);
        chartDialog->setWindowTitle("Chart Histogram");
        chartDialog->exec();  // 새로운 창 열기
        delete chartDialog;
        chartDialog = nullptr;
        chart_on_flag=0;
    }
}

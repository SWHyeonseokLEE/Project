#include "mainwindow.h"
#include "./ui_mainwindow.h"

//#include "lib/CAN_Access.h"
//tab1
QString g_msg_dbc="";

int g_msg_cnt=0;
int g_sg_cnt[100]={0,};

//ChartDialog *chartDialog=nullptr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),tcpServer(nullptr), clientSocket(nullptr),chartDialog(nullptr)

{
    ui->setupUi(this);
    g_sg_cnt[0]=1;

    tcpServer = new QTcpServer(this);
    if(tcpServer->listen(QHostAddress::Any, 12345))
    {
        connect(tcpServer, &QTcpServer::newConnection, this, &MainWindow::on_NewConnection);
    }

    ui->txt_DBCfilepath->setText("");

    ui->NUM_TPS->setDigitCount(6);
    ui->NUM_RPM->setDigitCount(6);
    ui->NUM_VS->setDigitCount(6);
    ui->NUM_TEMP_ENG->setDigitCount(6);
    ui->NUM_SAS_Angle->setDigitCount(6);
    chart_on_flag=0;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDI);
    timer->start(20);

    timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, this, &MainWindow::updateDO);
    timer1->start(10);
}

MainWindow::~MainWindow()
{
    tcpServer->close();
    delete ui;
}


void MainWindow::on_bt_msg_clicked()
{
    QString CAN_id = ui->MSG_CANID_lineEdit->text();
    QString msg_name = ui->MSG_name_lineEdit->text();
    QString msg_len = QString::number(ui->msg_length->value());
    QString msg_cm = ui->MSG_comm_lineEdit->text();

    if (CAN_id.isEmpty() || msg_name.isEmpty() || msg_len.isEmpty() || g_sg_cnt[g_msg_cnt] == 0) {
    } else {
        g_msg_cnt++;

        QString msg_text = "";
        if (!g_msg_dbc.isEmpty()) g_msg_dbc = g_msg_dbc + "\n";
        msg_text = "BO_ " +
                   CAN_id + " " +
                   msg_name + ": " +
                   msg_len + " " +
                   msg_cm;
        g_msg_dbc = g_msg_dbc + msg_text;
    }
    ui->DBC_temp->setText(g_msg_dbc);
    ui->DBC_temp->verticalScrollBar()->setValue(ui->DBC_temp->verticalScrollBar()->maximum());
}


void MainWindow::on_bt_signal_clicked()
{
    QString sg_name = ui->SG_name_lineEdit->text();
    QString sg_start = QString::number(ui->sg_start->value());
    QString sg_len = QString::number(ui->sg_length->value());
    QString sg_endian = ui->sg_endian->currentText();
    QString sg_type = ui->sg_type->currentText();
    QString sg_factor = ui->SG_factor_lineEdit->text();
    QString sg_offset = ui->SG_offset_lineEdit->text();
    QString sg_min = ui->SG_min_lineEdit->text();
    QString sg_max = ui->SG_max_lineEdit->text();
    QString sg_unit = ui->SG_unit_lineEdit->text();
    QString sg_cm = ui->SG_comm_lineEdit->text();

    if(sg_name.isEmpty() || sg_factor.isEmpty() || sg_offset.isEmpty() || sg_min.isEmpty() || sg_max.isEmpty() || sg_unit.isEmpty() || g_msg_cnt != 0)
    {
        if (sg_endian == "Little")
        {
            sg_endian = "@1";
        }
        else
        {
            sg_endian = "@0";
        }

        if (sg_type == "Signed")
        {
            sg_type = "-";
        }
        else
        {
            sg_type = "+";
        }

        g_sg_cnt[g_msg_cnt]++;
        QString sg_text = "\n SG_ " +
                          sg_name + " : " +
                          sg_start + "|" +
                          sg_len +
                          sg_endian +
                          sg_type + " (" +
                          sg_factor + "," +
                          sg_offset + ") [" +
                          sg_min + "|" +
                          sg_max + "] \"" +
                          sg_unit + "\" " +
                          sg_cm;

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
        if (lastline_index != -1)
        {
            g_msg_dbc = g_msg_dbc.left(lastline_index);
        }
        else
        {
            g_msg_dbc.clear();
        }

        if(g_sg_cnt[g_msg_cnt] ==0)
        {
            g_msg_cnt--;
        }
        else
        {
            g_sg_cnt[g_msg_cnt]--;
        }
    }
    ui->DBC_temp->setText(g_msg_dbc);
    ui->DBC_temp->verticalScrollBar()->setValue(ui->DBC_temp->verticalScrollBar()->maximum());
}


void MainWindow::on_bt_save_clicked()
{
    if (g_sg_cnt[g_msg_cnt] != 0 && g_msg_cnt != 0)
    {
        QString init_file_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QString file_path = QFileDialog::getSaveFileName(this, tr("Save DBC File"), init_file_path, tr("DBC Files (*.dbc);;All Files (*)"));

        if (!file_path.isEmpty())
        {
            QFile file(file_path);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&file);
                out << g_msg_dbc;
                file.close();
            }
        }
    }
}


void MainWindow::on_bt_addDBC_clicked()
{
    if (g_sg_cnt[g_msg_cnt] != 0 && g_msg_cnt != 0) {
        QString init_file_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QString file_path = QFileDialog::getOpenFileName(this, tr("Open DBC File"), init_file_path, tr("DBC Files (*.dbc);;All Files (*)"));

        if (!file_path.isEmpty()) {
            QFile file(file_path);
            if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)) {
                QTextStream out(&file);
                out.seek(file.size());
                g_msg_dbc = "\n" + g_msg_dbc;
                out << g_msg_dbc;
                file.close();
            }
        }
    }
}


QVector<Message> messages ;

void MainWindow::on_bt_OpenDBC_clicked()
{
    // 파일 탐색기창 제목
    QString str_caption = "Open File";
    QString str_dir     = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString str_filters = "DBC files (*.dbc);; All Files (*.*)";
    // 파일 저장할 폴더 경로 가져오기
    QString filePathDBC = QFileDialog::getOpenFileName(this, str_caption, str_dir, str_filters);
    QFile fileDBC(filePathDBC);

    if(!fileDBC.exists())
    {
        return;
    }

    messages = DBCParse::parseDBCToMessages(filePathDBC);
    if(messages.isEmpty())
    {
        return;
    }
    std::sort(messages.begin(), messages.end(), [](const Message &m1, const Message &m2) {
        return m1.id < m2.id;
    });

    ui->txt_DBCfilepath->setText(filePathDBC);
    ui->sg_select_combo->clear();

    ui->msg_table->setColumnCount(3);
    ui->msg_table->setHorizontalHeaderLabels(QStringList() << "Name" << "ID" << "Data Length");

    for(int i = 0; i < messages.size(); ++i)
    {

        QList<QStandardItem*> rowItems;
        ui->sg_select_combo->addItem(QString::number(messages[i].id));
        ui->sg_select_combo_2->addItem(QString::number(messages[i].id));

        int rowCount = ui->msg_table->rowCount();
        ui->msg_table->insertRow(rowCount);

        // 데이터 삽입
        ui->msg_table->setItem(rowCount, 0, new QTableWidgetItem(messages[i].name));
        ui->msg_table->setItem(rowCount, 1, new QTableWidgetItem(QString::number(messages[i].id)));
        ui->msg_table->setItem(rowCount, 2, new QTableWidgetItem(QString::number(messages[i].dl)));

    }

    ui->msg_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->msg_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_sg_select_combo_currentIndexChanged(int index)
{
    if (index >= 0 && index < messages.size())
    {
        const QVector<Signal> &signalList = messages[index].signalList;

        ui->sg_table->setColumnCount(9);
        ui->sg_table->setRowCount(0);
        ui->sg_table->setHorizontalHeaderLabels(QStringList() << "Name" << "Start Bit" << "Length" << "Endian" << "Scale" << "Offset" << "Min" << "Max" << "Unit");

        for (int i = 0; i < signalList.size(); ++i)
        {
            const Signal &signal = signalList[i];

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
        for (const Signal &signal : messages[ui->sg_select_combo_2->currentIndex()].signalList)
        {
            headerLabels <<signal.name;
        }

        ui->live_table->setHorizontalHeaderLabels(headerLabels);
        ui->live_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        if(ui->live_table->rowCount()==0)
        {
            ui->live_table->insertRow(0);
        }

        ui->live_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        live_end_flag=2;
    }
}

void MainWindow::on_pushButton_mode2_clicked()
{
    if(live_end_flag ==1 && messages.size() > 0)
    {
        ui->live_table->setRowCount(0);
        ui->live_table->setColumnCount(5);

        QStringList headerLabels;
        headerLabels << "Throttle Position"<<"RPM"<<"Vehicle Speed"<<"Engine Temperature"<<"Steer Angle";

        ui->live_table->setHorizontalHeaderLabels(headerLabels);
        ui->live_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        if(ui->live_table->rowCount()==0)
        {
            ui->live_table->insertRow(0);
        }

        ui->live_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        live_end_flag=3;
    }
}


void MainWindow::on_pushButton_close_clicked()
{
    if(live_end_flag >1)
    {
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
    connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindow::on_DisConnection);
    live_end_flag=1;
}


void MainWindow::on_DisConnection()
{
    live_end_flag=0;
    clientSocket->deleteLater();
}

#define MASK64(nbits) ((0xffffffffffffffff)>> (64-nbits))
double MainWindow::dcodeMsgSg(int msg_id, const char* sg_name, const QString& _data, QLCDNumber* lcd)
{
    QStringList parts = _data.split(' ',Qt::SkipEmptyParts);
    int ID= parts[0].toInt(nullptr,16);
    if(ID != msg_id)
    {
        return 7777;
    }
    int length=parts[1].toInt();
    uint8_t data[8]= {0,};
    for (int i = 0; i < length; ++i)
    {
        data[i] = parts[2 + i].toInt(nullptr, 16);
    }

    int msg_address=-1;
    for(int i=0;i<messages.size();i++)
    {
        if(messages[i].id==msg_id)msg_address=i;
    }

    if(msg_address<0)return 7777;

    int sg_address=-1;
    for(int i=0;i<messages[msg_address].signalList.size();i++)
    {
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

void MainWindow::decodeCan(QString _data)
{

        QStringList parts = _data.split(' ',Qt::SkipEmptyParts);
        int ID= parts[0].toInt(nullptr,16);
        if(ID != messages[ui->sg_select_combo_2->currentIndex()].id)
        {
            return;
        }
        int length=parts[1].toInt();
        uint8_t data[8]= {0,};

        for (int i = 0; i < length; ++i)
        {
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


void MainWindow::decodeDIDO(const QString& _data)
{
    QStringList parts = _data.split(' ', Qt::SkipEmptyParts);
    int ID = parts[0].right(2).toInt(nullptr, 16);
    if (ID != ui->Address_lineEdit->text().toInt(nullptr))
    {
        return;
    }
    int function_code = parts[0].left(1).toInt(nullptr, 16);
    if (function_code != 3)
    {
        return;
    }
    int DI_channel = parts[2].toInt(nullptr, 16);
    bool DI_screen[8] = {0,};
    for (int i = 0; i < 8; i++)
    {
        DI_screen[i] = DI_channel >> i & 0x01;
    }

    setDIChannel(ui->DI_1, DI_screen[0]);
    setDIChannel(ui->DI_2, DI_screen[1]);
    setDIChannel(ui->DI_3, DI_screen[2]);
    setDIChannel(ui->DI_4, DI_screen[3]);
    setDIChannel(ui->DI_5, DI_screen[4]);
    setDIChannel(ui->DI_6, DI_screen[5]);
    setDIChannel(ui->DI_7, DI_screen[6]);
    setDIChannel(ui->DI_8, DI_screen[7]);
}

void MainWindow::setDIChannel(QLabel *channel, bool state)
{
    if (state)
    {
        channel->setStyleSheet("background-color: #FFFF00;");
        channel->setText("On");
    }
    else
    {
        channel->setStyleSheet("background-color: #FFFFFF;");
        channel->setText("");
    }
}


void MainWindow::on_ReadyRead()
{
    if(di_flag==1||do_flag==1)
    {
        QByteArray data = clientSocket->read(29);
        qDebug() << "Received:" << QString(data);
        decodeDIDO(data);
    }
    else
    {
        QByteArray data = clientSocket->read(5);
        qDebug() << "Received:" << QString(data);
        if (data.size() == 5)
        {
            data.append(clientSocket->read(static_cast<quint8>(data[4])));
        }
        if(live_end_flag ==2)
        {
            decodeCan(data);
        }
        else if(live_end_flag == 3 && chart_on_flag == 1)
        {
            chartDialog->appendTPS(dcodeMsgSg(809,"TPS",data,ui->NUM_TPS));
            chartDialog->appendRPM(dcodeMsgSg(790,"N",data,ui->NUM_RPM));
            chartDialog->appendVS(dcodeMsgSg(790,"VS",data,ui->NUM_VS));
            chartDialog->appendTEMPENG(dcodeMsgSg(809,"TEMP_ENG",data,ui->NUM_TEMP_ENG));
            chartDialog->appendSASANGLE(dcodeMsgSg(688,"SAS_Angle",data,ui->NUM_SAS_Angle));
        }
        else if(live_end_flag == 3)
        {
            dcodeMsgSg(809,"TPS",data,ui->NUM_TPS);
            dcodeMsgSg(790,"N",data,ui->NUM_RPM);
            dcodeMsgSg(790,"VS",data,ui->NUM_VS);
            dcodeMsgSg(809,"TEMP_ENG",data,ui->NUM_TEMP_ENG);
            dcodeMsgSg(688,"SAS_Angle",data,ui->NUM_SAS_Angle);
        }
    }

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

void MainWindow::on_DI_checkBox_clicked(bool checked)
{
    di_flag=checked;
}

void MainWindow::on_DO_checkBox_clicked(bool checked)
{
    do_flag=checked;
}
void MainWindow::updateDI()
{
    if(di_flag && live_end_flag)
    {
        QString send_data="3"+hexAddress +" 8"+" 00 00 00 00 00 00 00 00";

        QByteArray data = send_data.toUtf8();
        clientSocket->write(data);
    }
}


void MainWindow::updateDO()
{
    if (do_flag && live_end_flag)
    {
        bool DO_dataset[8] = {0,};
        int DO_data = 0;

        DO_dataset[0] = ui->DO_checkBox_1->isChecked();
        DO_dataset[1] = ui->DO_checkBox_2->isChecked();
        DO_dataset[2] = ui->DO_checkBox_3->isChecked();
        DO_dataset[3] = ui->DO_checkBox_4->isChecked();
        DO_dataset[4] = ui->DO_checkBox_5->isChecked();
        DO_dataset[5] = ui->DO_checkBox_6->isChecked();
        DO_dataset[6] = ui->DO_checkBox_7->isChecked();
        DO_dataset[7] = ui->DO_checkBox_8->isChecked();

        for (int i = 0; i < 8; i++)
        {
            DO_data += DO_dataset[i] << i;
        }

        QString hexDOData = QString::number(DO_data, 16).toUpper();
        hexDOData = hexDOData.rightJustified(2, '0');
        QString send_data = "1" + hexAddress + " 8 " + hexDOData + " 00 00 00 00 00 00 00";
        QByteArray data = send_data.toUtf8();
        clientSocket->write(data);
    }
}




void MainWindow::on_Address_lineEdit_textChanged(const QString &arg1)
{
    hexAddress = QString::number(arg1.toInt(nullptr), 16).toUpper();
    hexAddress = hexAddress.rightJustified(2, '0');
}

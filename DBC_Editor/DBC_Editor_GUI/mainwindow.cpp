#include "mainwindow.h"
#include "./ui_mainwindow.h"


QString g_msg_dbc="";
int g_msg_cnt=0;
int g_sg_cnt[100]={0,};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    tcpServer(nullptr),
    clientSocket(nullptr)

{
    ui->setupUi(this);
    g_sg_cnt[0]=1;

    tcpServer = new QTcpServer(this);
    // Listen for incoming connections
    if(tcpServer->listen(QHostAddress::Any, 12345)) {
        connect(tcpServer, &QTcpServer::newConnection, this, &MainWindow::on_NewConnection);
    }

    ui->txt_DBCfilepath->setText("");
}


MainWindow::~MainWindow()
{
    tcpServer->close();
    delete ui;
}


void MainWindow::on_Add_msg_clicked()
{

    QString CAN_id = ui->CAN_ID->toPlainText();
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

void MainWindow::on_Add_signal_clicked()
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

void MainWindow::on_Del_Line_clicked()
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

void MainWindow::on_Save_DBC_clicked()
{
    if(g_sg_cnt[g_msg_cnt] != 0 && g_msg_cnt > 0)
    {
        QString file_path = QFileDialog::getSaveFileName(this, tr("Save DBC File"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("DBC Files (*.dbc);;All Files (*)"));
        if (!file_path.isEmpty()) {
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


void MainWindow::on_Add_DBC_clicked()
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

void MainWindow::on_Open_DBC_clicked()
{
    // 파일 탐색기창 제목
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

        ui->sg_table->setColumnCount(9);
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

        // 시그널 테이블 모델 설정

        ui->sg_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->sg_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}


void MainWindow::on_NewConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &MainWindow::on_ReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
}


#define MASK64(nbits) ((0xffffffffffffffff)>> (64-nbits))


void MainWindow::dcodeMsgSg(int msg_id, const char* sg_name, const QString& _data,int colindex){
    QStringList parts = _data.split(' ',Qt::SkipEmptyParts);
    int ID= parts[0].toInt(nullptr,16);
    if(ID != msg_id)
    {
        return;
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
    if(msg_address<0)return;
    int sg_address=-1;
    for(int i=0;i<messages[msg_address].signalList.size();i++)
    {
        if(messages[msg_address].signalList[i].name==sg_name)sg_address=i;
    }
    if(sg_address<0)return;
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
    QTableWidgetItem *item = new QTableWidgetItem(QString::number(scaledValue));
    ui->live_table->setItem(0, colindex, item);
}


void MainWindow::decodeCan(QString _data)
{

    QStringList parts = _data.split(' ',Qt::SkipEmptyParts);
    int ID= parts[0].toInt();
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


void MainWindow::on_ReadyRead()
{
    QByteArray data = clientSocket->readAll();

    dcodeMsgSg(809,"TPS",data,0);
    dcodeMsgSg(790,"N",data,1);
    dcodeMsgSg(790,"VS",data,2);
    dcodeMsgSg(809,"TEMP_ENG",data,3);
    dcodeMsgSg(688,"SAS_Angle",data,4);
    //dcodeMsgSg(545, "TEMP_FUEL" ,data,4);
    //dcodeMsgSg(688,"SAS_Angle",data,4);

    // 수신 데이터 표시
    ui->txt_t3->setText(QString(data));
}



void MainWindow::on_sg_select_combo_2_currentIndexChanged(int index)
{

    ui->live_table->clear();
    ui->live_table->setColumnCount(5);

    QStringList headerLabels;

    headerLabels << "Throttle Position"<<"RPM"<<"Vehicle Speed"<<"Engine Temperature"<<"Steering Angle";

    ui->live_table->setHorizontalHeaderLabels(headerLabels);
    ui->live_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    if(ui->live_table->rowCount()==0)
    {
        ui->live_table->insertRow(0);
    }
}

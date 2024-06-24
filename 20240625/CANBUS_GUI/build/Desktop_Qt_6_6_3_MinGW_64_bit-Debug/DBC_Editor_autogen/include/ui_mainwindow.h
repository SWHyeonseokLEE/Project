/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_14;
    QSpinBox *sg_length;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_17;
    QTextBrowser *DBC_File;
    QPushButton *bt_addDBC;
    QLabel *label_8;
    QPushButton *bt_signal;
    QComboBox *sg_type;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_7;
    QLabel *label_13;
    QPushButton *bt_del_lastline;
    QLabel *label_5;
    QLabel *label_12;
    QSpinBox *sg_start;
    QSpinBox *msg_length;
    QLabel *label_2;
    QPushButton *bt_msg;
    QPushButton *bt_save;
    QComboBox *sg_endian;
    QLabel *label_9;
    QLineEdit *MSG_CANID_lineEdit;
    QLineEdit *MSG_name_lineEdit;
    QLineEdit *MSG_comm_lineEdit;
    QLineEdit *SG_name_lineEdit;
    QLineEdit *SG_factor_lineEdit;
    QLineEdit *SG_offset_lineEdit;
    QLineEdit *SG_min_lineEdit;
    QLineEdit *SG_max_lineEdit;
    QLineEdit *SG_unit_lineEdit;
    QLineEdit *SG_comm_lineEdit;
    QLabel *label_19;
    QWidget *tab_2;
    QTextBrowser *txt_DBCfilepath;
    QPushButton *bt_FileOpen;
    QComboBox *sg_select_combo;
    QTableWidget *sg_table;
    QTableWidget *MSG_table;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *tab_3;
    QPushButton *pushButton_mode1;
    QPushButton *pushButton_mode2;
    QComboBox *sg_select_combo_2;
    QLabel *label_24;
    QPushButton *pushButton_close;
    QTableWidget *live_table;
    QLCDNumber *NUM_TPS;
    QLabel *label_28;
    QLabel *label_29;
    QLCDNumber *NUM_RPM;
    QLabel *label_30;
    QLCDNumber *NUM_VS;
    QLabel *label_31;
    QLCDNumber *NUM_TEMP_ENG;
    QLCDNumber *NUM_SAS_Angle;
    QLabel *label_32;
    QPushButton *bt_plotter;
    QWidget *tab_4;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QCheckBox *DI_checkBox;
    QCheckBox *DO_checkBox;
    QLineEdit *Address_lineEdit;
    QCheckBox *DO_checkBox_1;
    QCheckBox *DO_checkBox_2;
    QCheckBox *DO_checkBox_3;
    QCheckBox *DO_checkBox_4;
    QCheckBox *DO_checkBox_5;
    QCheckBox *DO_checkBox_6;
    QCheckBox *DO_checkBox_7;
    QCheckBox *DO_checkBox_8;
    QLabel *label_22;
    QLabel *DI_1;
    QLabel *DI_2;
    QLabel *DI_3;
    QLabel *DI_4;
    QLabel *DI_5;
    QLabel *DI_6;
    QLabel *DI_7;
    QLabel *DI_8;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(620, 799);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 621, 781));
        QFont font;
        font.setPointSize(9);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 220, 48, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 220, 81, 16));
        label_14 = new QLabel(tab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(270, 270, 48, 16));
        sg_length = new QSpinBox(tab);
        sg_length->setObjectName("sg_length");
        sg_length->setGeometry(QRect(270, 240, 61, 21));
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(300, 60, 41, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 110, 61, 16));
        label_17 = new QLabel(tab);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(470, 220, 48, 16));
        DBC_File = new QTextBrowser(tab);
        DBC_File->setObjectName("DBC_File");
        DBC_File->setGeometry(QRect(40, 440, 521, 251));
        bt_addDBC = new QPushButton(tab);
        bt_addDBC->setObjectName("bt_addDBC");
        bt_addDBC->setGeometry(QRect(390, 700, 81, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(470, 270, 48, 16));
        bt_signal = new QPushButton(tab);
        bt_signal->setObjectName("bt_signal");
        bt_signal->setGeometry(QRect(420, 370, 141, 16));
        sg_type = new QComboBox(tab);
        sg_type->addItem(QString());
        sg_type->addItem(QString());
        sg_type->setObjectName("sg_type");
        sg_type->setGeometry(QRect(470, 240, 91, 21));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 60, 48, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 270, 48, 16));
        label_15 = new QLabel(tab);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(370, 270, 48, 16));
        label_16 = new QLabel(tab);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(370, 220, 48, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 270, 48, 16));
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 190, 141, 31));
        QFont font1;
        font1.setPointSize(15);
        label_13->setFont(font1);
        bt_del_lastline = new QPushButton(tab);
        bt_del_lastline->setObjectName("bt_del_lastline");
        bt_del_lastline->setGeometry(QRect(40, 700, 81, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(270, 220, 48, 16));
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 30, 101, 31));
        label_12->setFont(font1);
        sg_start = new QSpinBox(tab);
        sg_start->setObjectName("sg_start");
        sg_start->setGeometry(QRect(170, 240, 61, 21));
        msg_length = new QSpinBox(tab);
        msg_length->setObjectName("msg_length");
        msg_length->setGeometry(QRect(300, 80, 51, 21));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 48, 16));
        bt_msg = new QPushButton(tab);
        bt_msg->setObjectName("bt_msg");
        bt_msg->setGeometry(QRect(420, 160, 141, 16));
        bt_save = new QPushButton(tab);
        bt_save->setObjectName("bt_save");
        bt_save->setGeometry(QRect(480, 700, 81, 16));
        sg_endian = new QComboBox(tab);
        sg_endian->addItem(QString());
        sg_endian->addItem(QString());
        sg_endian->setObjectName("sg_endian");
        sg_endian->setGeometry(QRect(370, 240, 61, 21));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 320, 61, 16));
        MSG_CANID_lineEdit = new QLineEdit(tab);
        MSG_CANID_lineEdit->setObjectName("MSG_CANID_lineEdit");
        MSG_CANID_lineEdit->setGeometry(QRect(170, 80, 91, 20));
        MSG_name_lineEdit = new QLineEdit(tab);
        MSG_name_lineEdit->setObjectName("MSG_name_lineEdit");
        MSG_name_lineEdit->setGeometry(QRect(40, 80, 91, 20));
        MSG_comm_lineEdit = new QLineEdit(tab);
        MSG_comm_lineEdit->setObjectName("MSG_comm_lineEdit");
        MSG_comm_lineEdit->setGeometry(QRect(40, 130, 521, 20));
        SG_name_lineEdit = new QLineEdit(tab);
        SG_name_lineEdit->setObjectName("SG_name_lineEdit");
        SG_name_lineEdit->setGeometry(QRect(40, 240, 91, 20));
        SG_factor_lineEdit = new QLineEdit(tab);
        SG_factor_lineEdit->setObjectName("SG_factor_lineEdit");
        SG_factor_lineEdit->setGeometry(QRect(40, 290, 91, 20));
        SG_offset_lineEdit = new QLineEdit(tab);
        SG_offset_lineEdit->setObjectName("SG_offset_lineEdit");
        SG_offset_lineEdit->setGeometry(QRect(170, 290, 61, 20));
        SG_min_lineEdit = new QLineEdit(tab);
        SG_min_lineEdit->setObjectName("SG_min_lineEdit");
        SG_min_lineEdit->setGeometry(QRect(270, 290, 61, 20));
        SG_max_lineEdit = new QLineEdit(tab);
        SG_max_lineEdit->setObjectName("SG_max_lineEdit");
        SG_max_lineEdit->setGeometry(QRect(370, 290, 61, 20));
        SG_unit_lineEdit = new QLineEdit(tab);
        SG_unit_lineEdit->setObjectName("SG_unit_lineEdit");
        SG_unit_lineEdit->setGeometry(QRect(472, 290, 91, 20));
        SG_comm_lineEdit = new QLineEdit(tab);
        SG_comm_lineEdit->setObjectName("SG_comm_lineEdit");
        SG_comm_lineEdit->setGeometry(QRect(40, 340, 521, 20));
        label_19 = new QLabel(tab);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(30, 400, 141, 31));
        label_19->setFont(font1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        txt_DBCfilepath = new QTextBrowser(tab_2);
        txt_DBCfilepath->setObjectName("txt_DBCfilepath");
        txt_DBCfilepath->setGeometry(QRect(40, 60, 451, 31));
        txt_DBCfilepath->setFont(font);
        bt_FileOpen = new QPushButton(tab_2);
        bt_FileOpen->setObjectName("bt_FileOpen");
        bt_FileOpen->setGeometry(QRect(490, 60, 81, 31));
        sg_select_combo = new QComboBox(tab_2);
        sg_select_combo->setObjectName("sg_select_combo");
        sg_select_combo->setGeometry(QRect(140, 360, 69, 22));
        sg_table = new QTableWidget(tab_2);
        sg_table->setObjectName("sg_table");
        sg_table->setGeometry(QRect(40, 390, 531, 341));
        MSG_table = new QTableWidget(tab_2);
        MSG_table->setObjectName("MSG_table");
        MSG_table->setGeometry(QRect(40, 140, 531, 181));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(40, 30, 101, 31));
        label_18->setFont(font1);
        label_20 = new QLabel(tab_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(40, 110, 101, 31));
        label_20->setFont(font1);
        label_21 = new QLabel(tab_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(40, 350, 101, 31));
        label_21->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        pushButton_mode1 = new QPushButton(tab_3);
        pushButton_mode1->setObjectName("pushButton_mode1");
        pushButton_mode1->setGeometry(QRect(530, 40, 51, 16));
        pushButton_mode2 = new QPushButton(tab_3);
        pushButton_mode2->setObjectName("pushButton_mode2");
        pushButton_mode2->setGeometry(QRect(530, 60, 51, 16));
        sg_select_combo_2 = new QComboBox(tab_3);
        sg_select_combo_2->setObjectName("sg_select_combo_2");
        sg_select_combo_2->setGeometry(QRect(90, 20, 69, 16));
        label_24 = new QLabel(tab_3);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(40, 20, 31, 16));
        label_24->setFont(font);
        pushButton_close = new QPushButton(tab_3);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setGeometry(QRect(530, 100, 51, 16));
        live_table = new QTableWidget(tab_3);
        live_table->setObjectName("live_table");
        live_table->setGeometry(QRect(40, 40, 481, 131));
        NUM_TPS = new QLCDNumber(tab_3);
        NUM_TPS->setObjectName("NUM_TPS");
        NUM_TPS->setGeometry(QRect(10, 200, 111, 41));
        label_28 = new QLabel(tab_3);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 180, 101, 16));
        label_28->setFont(font);
        label_29 = new QLabel(tab_3);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(250, 180, 101, 16));
        label_29->setFont(font);
        NUM_RPM = new QLCDNumber(tab_3);
        NUM_RPM->setObjectName("NUM_RPM");
        NUM_RPM->setGeometry(QRect(250, 200, 111, 41));
        label_30 = new QLabel(tab_3);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(130, 180, 101, 16));
        label_30->setFont(font);
        NUM_VS = new QLCDNumber(tab_3);
        NUM_VS->setObjectName("NUM_VS");
        NUM_VS->setGeometry(QRect(130, 200, 111, 41));
        label_31 = new QLabel(tab_3);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(490, 180, 101, 16));
        label_31->setFont(font);
        NUM_TEMP_ENG = new QLCDNumber(tab_3);
        NUM_TEMP_ENG->setObjectName("NUM_TEMP_ENG");
        NUM_TEMP_ENG->setGeometry(QRect(490, 200, 111, 41));
        NUM_SAS_Angle = new QLCDNumber(tab_3);
        NUM_SAS_Angle->setObjectName("NUM_SAS_Angle");
        NUM_SAS_Angle->setGeometry(QRect(370, 200, 111, 41));
        label_32 = new QLabel(tab_3);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(370, 180, 101, 16));
        label_32->setFont(font);
        bt_plotter = new QPushButton(tab_3);
        bt_plotter->setObjectName("bt_plotter");
        bt_plotter->setGeometry(QRect(530, 80, 51, 16));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_33 = new QLabel(tab_4);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(90, 150, 31, 31));
        label_34 = new QLabel(tab_4);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(90, 190, 31, 31));
        label_35 = new QLabel(tab_4);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(90, 310, 31, 31));
        label_36 = new QLabel(tab_4);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(90, 230, 31, 31));
        label_37 = new QLabel(tab_4);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(90, 270, 31, 31));
        label_38 = new QLabel(tab_4);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(90, 350, 31, 31));
        label_39 = new QLabel(tab_4);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(90, 390, 31, 31));
        label_40 = new QLabel(tab_4);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(90, 430, 31, 31));
        DI_checkBox = new QCheckBox(tab_4);
        DI_checkBox->setObjectName("DI_checkBox");
        DI_checkBox->setGeometry(QRect(40, 120, 111, 21));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        DI_checkBox->setFont(font2);
        DO_checkBox = new QCheckBox(tab_4);
        DO_checkBox->setObjectName("DO_checkBox");
        DO_checkBox->setGeometry(QRect(380, 120, 131, 20));
        DO_checkBox->setFont(font2);
        Address_lineEdit = new QLineEdit(tab_4);
        Address_lineEdit->setObjectName("Address_lineEdit");
        Address_lineEdit->setGeometry(QRect(240, 60, 113, 16));
        DO_checkBox_1 = new QCheckBox(tab_4);
        DO_checkBox_1->setObjectName("DO_checkBox_1");
        DO_checkBox_1->setGeometry(QRect(450, 150, 101, 18));
        DO_checkBox_2 = new QCheckBox(tab_4);
        DO_checkBox_2->setObjectName("DO_checkBox_2");
        DO_checkBox_2->setGeometry(QRect(450, 190, 121, 18));
        DO_checkBox_3 = new QCheckBox(tab_4);
        DO_checkBox_3->setObjectName("DO_checkBox_3");
        DO_checkBox_3->setGeometry(QRect(450, 230, 131, 18));
        DO_checkBox_4 = new QCheckBox(tab_4);
        DO_checkBox_4->setObjectName("DO_checkBox_4");
        DO_checkBox_4->setGeometry(QRect(450, 270, 151, 18));
        DO_checkBox_5 = new QCheckBox(tab_4);
        DO_checkBox_5->setObjectName("DO_checkBox_5");
        DO_checkBox_5->setGeometry(QRect(450, 310, 151, 18));
        DO_checkBox_6 = new QCheckBox(tab_4);
        DO_checkBox_6->setObjectName("DO_checkBox_6");
        DO_checkBox_6->setGeometry(QRect(450, 350, 141, 18));
        DO_checkBox_7 = new QCheckBox(tab_4);
        DO_checkBox_7->setObjectName("DO_checkBox_7");
        DO_checkBox_7->setGeometry(QRect(450, 390, 141, 18));
        DO_checkBox_8 = new QCheckBox(tab_4);
        DO_checkBox_8->setObjectName("DO_checkBox_8");
        DO_checkBox_8->setGeometry(QRect(450, 430, 151, 18));
        label_22 = new QLabel(tab_4);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(260, 30, 111, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        label_22->setFont(font3);
        DI_1 = new QLabel(tab_4);
        DI_1->setObjectName("DI_1");
        DI_1->setGeometry(QRect(140, 150, 31, 31));
        DI_2 = new QLabel(tab_4);
        DI_2->setObjectName("DI_2");
        DI_2->setGeometry(QRect(140, 190, 31, 31));
        DI_3 = new QLabel(tab_4);
        DI_3->setObjectName("DI_3");
        DI_3->setGeometry(QRect(140, 230, 38, 31));
        DI_4 = new QLabel(tab_4);
        DI_4->setObjectName("DI_4");
        DI_4->setGeometry(QRect(140, 270, 38, 31));
        DI_5 = new QLabel(tab_4);
        DI_5->setObjectName("DI_5");
        DI_5->setGeometry(QRect(140, 310, 38, 31));
        DI_6 = new QLabel(tab_4);
        DI_6->setObjectName("DI_6");
        DI_6->setGeometry(QRect(140, 350, 38, 31));
        DI_7 = new QLabel(tab_4);
        DI_7->setObjectName("DI_7");
        DI_7->setGeometry(QRect(140, 390, 38, 31));
        DI_8 = new QLabel(tab_4);
        DI_8->setObjectName("DI_8");
        DI_8->setGeometry(QRect(140, 430, 38, 31));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "DBC Editor for CAN Bus Database Files", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_4->setText(QCoreApplication::translate("MainWindow", "Bit Start", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Comment", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        bt_addDBC->setText(QCoreApplication::translate("MainWindow", "Add DBC", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Unit", nullptr));
        bt_signal->setText(QCoreApplication::translate("MainWindow", "Apply Signal Syntax", nullptr));
        sg_type->setItemText(0, QCoreApplication::translate("MainWindow", "Signed", nullptr));
        sg_type->setItemText(1, QCoreApplication::translate("MainWindow", "Unsigned", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "CAN ID", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Factor", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Endian", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "CAN Signals (EEC1)", nullptr));
        bt_del_lastline->setText(QCoreApplication::translate("MainWindow", "Delete Last Line", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "CAN Message", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        bt_msg->setText(QCoreApplication::translate("MainWindow", "Apply Message Syntax", nullptr));
        bt_save->setText(QCoreApplication::translate("MainWindow", "Save DBC", nullptr));
        sg_endian->setItemText(0, QCoreApplication::translate("MainWindow", "Little", nullptr));
        sg_endian->setItemText(1, QCoreApplication::translate("MainWindow", "Big", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "Comment", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "DBC File", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "DBC Writer", nullptr));
        bt_FileOpen->setText(QCoreApplication::translate("MainWindow", "File Open", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "DBC File Path", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "CAN Messages", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "CAN Signals", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "DBC Reader", nullptr));
        pushButton_mode1->setText(QCoreApplication::translate("MainWindow", "Mode 1", nullptr));
        pushButton_mode2->setText(QCoreApplication::translate("MainWindow", "Mode 2", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Throttle Position", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "RPM", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Vehicle Speed", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Engine Temperature", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Steering Angle", nullptr));
        bt_plotter->setText(QCoreApplication::translate("MainWindow", "Plotter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Received", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Ch.1", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Ch.2", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Ch.5", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Ch.3", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Ch.4", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Ch.6", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "Ch.7", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Ch.8", nullptr));
        DI_checkBox->setText(QCoreApplication::translate("MainWindow", "Digital Input", nullptr));
        DO_checkBox->setText(QCoreApplication::translate("MainWindow", "Digital Output", nullptr));
        DO_checkBox_1->setText(QCoreApplication::translate("MainWindow", "Channel_1", nullptr));
        DO_checkBox_2->setText(QCoreApplication::translate("MainWindow", "Channel_2", nullptr));
        DO_checkBox_3->setText(QCoreApplication::translate("MainWindow", "Channel_3", nullptr));
        DO_checkBox_4->setText(QCoreApplication::translate("MainWindow", "Channel_4", nullptr));
        DO_checkBox_5->setText(QCoreApplication::translate("MainWindow", "Channel_5", nullptr));
        DO_checkBox_6->setText(QCoreApplication::translate("MainWindow", "Channel_6", nullptr));
        DO_checkBox_7->setText(QCoreApplication::translate("MainWindow", "Channel_7", nullptr));
        DO_checkBox_8->setText(QCoreApplication::translate("MainWindow", "Channel_8", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        DI_1->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        DI_2->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        DI_3->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        DI_4->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        DI_5->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        DI_6->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        DI_7->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        DI_8->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "I/O Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

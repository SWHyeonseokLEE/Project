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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QTextEdit *sg_name;
    QTextEdit *CAN_ID;
    QLabel *label_3;
    QLabel *label_14;
    QSpinBox *sg_length;
    QTextEdit *sg_offset;
    QLabel *label_19;
    QLabel *label_10;
    QLabel *label_11;
    QTextEdit *sg_max;
    QLabel *label_17;
    QTextBrowser *DBC_temp;
    QTextBrowser *debug;
    QPushButton *bt_addDBC;
    QLabel *label_8;
    QTextEdit *msg_cm;
    QTextEdit *sg_factor;
    QPushButton *bt_signal;
    QTextEdit *msg_name;
    QComboBox *sg_type;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_7;
    QLabel *label_18;
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
    QTextEdit *sg_cm;
    QTextEdit *sg_unit;
    QLabel *label_9;
    QTextEdit *sg_min;
    QLabel *label_22;
    QWidget *tab_2;
    QTextBrowser *txt_DBCfilepath;
    QLabel *label_20;
    QPushButton *bt_OpenDBC;
    QTextBrowser *txt_debug_readtab;
    QLabel *label_23;
    QPushButton *bt_Clear;
    QLabel *label_26;
    QLabel *label_27;
    QComboBox *sg_select_combo;
    QTableWidget *sg_table;
    QTableWidget *msg_table;
    QWidget *tab_3;
    QPushButton *pushButton_mode1;
    QPushButton *pushButton_mode2;
    QComboBox *sg_select_combo_2;
    QTextBrowser *txt_debug_readtab_2;
    QLabel *label_24;
    QLabel *label_25;
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
    QPushButton *bt_chart;
    QPushButton *bt_histo;
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
        tabWidget->setGeometry(QRect(0, 10, 621, 781));
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(250, 230, 48, 16));
        sg_name = new QTextEdit(tab);
        sg_name->setObjectName("sg_name");
        sg_name->setGeometry(QRect(10, 250, 231, 31));
        QFont font;
        font.setPointSize(9);
        sg_name->setFont(font);
        CAN_ID = new QTextEdit(tab);
        CAN_ID->setObjectName("CAN_ID");
        CAN_ID->setGeometry(QRect(10, 100, 221, 31));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 230, 81, 16));
        label_14 = new QLabel(tab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(230, 290, 48, 16));
        sg_length = new QSpinBox(tab);
        sg_length->setObjectName("sg_length");
        sg_length->setGeometry(QRect(310, 250, 51, 31));
        sg_offset = new QTextEdit(tab);
        sg_offset->setObjectName("sg_offset");
        sg_offset->setGeometry(QRect(120, 310, 101, 31));
        label_19 = new QLabel(tab);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 410, 41, 16));
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(380, 80, 41, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 140, 61, 16));
        sg_max = new QTextEdit(tab);
        sg_max->setObjectName("sg_max");
        sg_max->setGeometry(QRect(330, 310, 91, 31));
        label_17 = new QLabel(tab);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(430, 230, 48, 16));
        DBC_temp = new QTextBrowser(tab);
        DBC_temp->setObjectName("DBC_temp");
        DBC_temp->setGeometry(QRect(10, 520, 511, 201));
        debug = new QTextBrowser(tab);
        debug->setObjectName("debug");
        debug->setGeometry(QRect(10, 430, 511, 51));
        QFont font1;
        font1.setPointSize(8);
        debug->setFont(font1);
        bt_addDBC = new QPushButton(tab);
        bt_addDBC->setObjectName("bt_addDBC");
        bt_addDBC->setGeometry(QRect(530, 650, 81, 31));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(430, 290, 48, 16));
        msg_cm = new QTextEdit(tab);
        msg_cm->setObjectName("msg_cm");
        msg_cm->setGeometry(QRect(10, 160, 511, 31));
        sg_factor = new QTextEdit(tab);
        sg_factor->setObjectName("sg_factor");
        sg_factor->setGeometry(QRect(10, 310, 101, 31));
        bt_signal = new QPushButton(tab);
        bt_signal->setObjectName("bt_signal");
        bt_signal->setGeometry(QRect(530, 560, 81, 31));
        msg_name = new QTextEdit(tab);
        msg_name->setObjectName("msg_name");
        msg_name->setGeometry(QRect(240, 100, 131, 31));
        sg_type = new QComboBox(tab);
        sg_type->addItem(QString());
        sg_type->addItem(QString());
        sg_type->setObjectName("sg_type");
        sg_type->setGeometry(QRect(430, 250, 91, 31));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 80, 48, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 290, 48, 16));
        label_15 = new QLabel(tab);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(330, 290, 48, 16));
        label_16 = new QLabel(tab);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(370, 230, 48, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(120, 290, 48, 16));
        label_18 = new QLabel(tab);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 500, 61, 16));
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 200, 101, 31));
        QFont font2;
        font2.setPointSize(15);
        label_13->setFont(font2);
        bt_del_lastline = new QPushButton(tab);
        bt_del_lastline->setObjectName("bt_del_lastline");
        bt_del_lastline->setGeometry(QRect(530, 600, 81, 41));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 230, 48, 16));
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 50, 101, 31));
        label_12->setFont(font2);
        sg_start = new QSpinBox(tab);
        sg_start->setObjectName("sg_start");
        sg_start->setGeometry(QRect(250, 250, 51, 31));
        msg_length = new QSpinBox(tab);
        msg_length->setObjectName("msg_length");
        msg_length->setGeometry(QRect(380, 100, 51, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 80, 48, 16));
        bt_msg = new QPushButton(tab);
        bt_msg->setObjectName("bt_msg");
        bt_msg->setGeometry(QRect(530, 520, 81, 31));
        bt_save = new QPushButton(tab);
        bt_save->setObjectName("bt_save");
        bt_save->setGeometry(QRect(530, 690, 81, 31));
        sg_endian = new QComboBox(tab);
        sg_endian->addItem(QString());
        sg_endian->addItem(QString());
        sg_endian->setObjectName("sg_endian");
        sg_endian->setGeometry(QRect(370, 250, 51, 31));
        sg_cm = new QTextEdit(tab);
        sg_cm->setObjectName("sg_cm");
        sg_cm->setGeometry(QRect(10, 370, 511, 31));
        sg_unit = new QTextEdit(tab);
        sg_unit->setObjectName("sg_unit");
        sg_unit->setGeometry(QRect(430, 310, 91, 31));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 350, 61, 16));
        sg_min = new QTextEdit(tab);
        sg_min->setObjectName("sg_min");
        sg_min->setGeometry(QRect(230, 310, 91, 31));
        label_22 = new QLabel(tab);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(240, 10, 101, 31));
        QFont font3;
        font3.setPointSize(19);
        label_22->setFont(font3);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        txt_DBCfilepath = new QTextBrowser(tab_2);
        txt_DBCfilepath->setObjectName("txt_DBCfilepath");
        txt_DBCfilepath->setGeometry(QRect(10, 30, 511, 31));
        txt_DBCfilepath->setFont(font);
        label_20 = new QLabel(tab_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 10, 101, 16));
        label_20->setFont(font);
        bt_OpenDBC = new QPushButton(tab_2);
        bt_OpenDBC->setObjectName("bt_OpenDBC");
        bt_OpenDBC->setGeometry(QRect(530, 30, 81, 31));
        txt_debug_readtab = new QTextBrowser(tab_2);
        txt_debug_readtab->setObjectName("txt_debug_readtab");
        txt_debug_readtab->setGeometry(QRect(10, 90, 511, 51));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 65, 81, 21));
        label_23->setFont(font);
        bt_Clear = new QPushButton(tab_2);
        bt_Clear->setObjectName("bt_Clear");
        bt_Clear->setGeometry(QRect(530, 90, 81, 51));
        label_26 = new QLabel(tab_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 145, 61, 21));
        label_26->setFont(font);
        label_27 = new QLabel(tab_2);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 360, 61, 31));
        label_27->setFont(font);
        sg_select_combo = new QComboBox(tab_2);
        sg_select_combo->setObjectName("sg_select_combo");
        sg_select_combo->setGeometry(QRect(60, 360, 69, 22));
        sg_table = new QTableWidget(tab_2);
        sg_table->setObjectName("sg_table");
        sg_table->setGeometry(QRect(10, 390, 601, 351));
        msg_table = new QTableWidget(tab_2);
        msg_table->setObjectName("msg_table");
        msg_table->setGeometry(QRect(10, 170, 601, 181));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        pushButton_mode1 = new QPushButton(tab_3);
        pushButton_mode1->setObjectName("pushButton_mode1");
        pushButton_mode1->setGeometry(QRect(460, 30, 71, 24));
        pushButton_mode2 = new QPushButton(tab_3);
        pushButton_mode2->setObjectName("pushButton_mode2");
        pushButton_mode2->setGeometry(QRect(540, 30, 71, 24));
        sg_select_combo_2 = new QComboBox(tab_3);
        sg_select_combo_2->setObjectName("sg_select_combo_2");
        sg_select_combo_2->setGeometry(QRect(460, 60, 69, 22));
        txt_debug_readtab_2 = new QTextBrowser(tab_3);
        txt_debug_readtab_2->setObjectName("txt_debug_readtab_2");
        txt_debug_readtab_2->setGeometry(QRect(10, 30, 441, 51));
        label_24 = new QLabel(tab_3);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 90, 81, 16));
        label_24->setFont(font);
        label_25 = new QLabel(tab_3);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 5, 81, 21));
        label_25->setFont(font);
        pushButton_close = new QPushButton(tab_3);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setGeometry(QRect(540, 60, 71, 24));
        live_table = new QTableWidget(tab_3);
        live_table->setObjectName("live_table");
        live_table->setGeometry(QRect(10, 110, 601, 61));
        NUM_TPS = new QLCDNumber(tab_3);
        NUM_TPS->setObjectName("NUM_TPS");
        NUM_TPS->setGeometry(QRect(10, 200, 111, 41));
        label_28 = new QLabel(tab_3);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 180, 101, 16));
        label_28->setFont(font);
        label_29 = new QLabel(tab_3);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(130, 180, 101, 16));
        label_29->setFont(font);
        NUM_RPM = new QLCDNumber(tab_3);
        NUM_RPM->setObjectName("NUM_RPM");
        NUM_RPM->setGeometry(QRect(130, 200, 111, 41));
        label_30 = new QLabel(tab_3);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(250, 180, 101, 16));
        label_30->setFont(font);
        NUM_VS = new QLCDNumber(tab_3);
        NUM_VS->setObjectName("NUM_VS");
        NUM_VS->setGeometry(QRect(250, 200, 111, 41));
        label_31 = new QLabel(tab_3);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(370, 180, 101, 16));
        label_31->setFont(font);
        NUM_TEMP_ENG = new QLCDNumber(tab_3);
        NUM_TEMP_ENG->setObjectName("NUM_TEMP_ENG");
        NUM_TEMP_ENG->setGeometry(QRect(370, 200, 111, 41));
        NUM_SAS_Angle = new QLCDNumber(tab_3);
        NUM_SAS_Angle->setObjectName("NUM_SAS_Angle");
        NUM_SAS_Angle->setGeometry(QRect(490, 200, 111, 41));
        label_32 = new QLabel(tab_3);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(490, 180, 101, 16));
        label_32->setFont(font);
        bt_chart = new QPushButton(tab_3);
        bt_chart->setObjectName("bt_chart");
        bt_chart->setGeometry(QRect(10, 280, 93, 29));
        bt_histo = new QPushButton(tab_3);
        bt_histo->setObjectName("bt_histo");
        bt_histo->setGeometry(QRect(110, 280, 93, 29));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


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
        label_19->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Comment", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        bt_addDBC->setText(QCoreApplication::translate("MainWindow", "Add DBC", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Unit", nullptr));
        bt_signal->setText(QCoreApplication::translate("MainWindow", "Add Signal", nullptr));
        sg_type->setItemText(0, QCoreApplication::translate("MainWindow", "Signed", nullptr));
        sg_type->setItemText(1, QCoreApplication::translate("MainWindow", "Unsigned", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "CAN ID", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Factor", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Endian", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "DBC File", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Signal", nullptr));
        bt_del_lastline->setText(QCoreApplication::translate("MainWindow", "Delete\n"
"Last Line", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        bt_msg->setText(QCoreApplication::translate("MainWindow", "Add Message", nullptr));
        bt_save->setText(QCoreApplication::translate("MainWindow", "Save DBC", nullptr));
        sg_endian->setItemText(0, QCoreApplication::translate("MainWindow", "Little", nullptr));
        sg_endian->setItemText(1, QCoreApplication::translate("MainWindow", "Big", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "Comment", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "DBC Edit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Edit", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "DBC File Path", nullptr));
        bt_OpenDBC->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        bt_Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Msg List", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Sg List", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Read", nullptr));
        pushButton_mode1->setText(QCoreApplication::translate("MainWindow", "Mode 1", nullptr));
        pushButton_mode2->setText(QCoreApplication::translate("MainWindow", "Mode 2", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\354\223\260\353\241\234\355\213\200 \355\215\274\354\204\274\355\212\270", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "RPM", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\354\206\215\353\217\204", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\354\227\224\354\247\204 \354\230\250\353\217\204", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\354\212\244\355\213\260\354\226\264 \352\260\201\353\217\204", nullptr));
        bt_chart->setText(QCoreApplication::translate("MainWindow", "Chart", nullptr));
        bt_histo->setText(QCoreApplication::translate("MainWindow", "Histogram", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Live", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

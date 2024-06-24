/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_bt_msg_clicked",
    "",
    "on_bt_del_lastline_clicked",
    "on_bt_signal_clicked",
    "on_bt_save_clicked",
    "on_bt_addDBC_clicked",
    "on_bt_FileOpen_clicked",
    "on_sg_select_combo_currentIndexChanged",
    "index",
    "on_pushButton_mode1_clicked",
    "on_pushButton_mode2_clicked",
    "on_pushButton_close_clicked",
    "on_bt_Clear_clicked",
    "setDIChannel",
    "QLabel*",
    "channel",
    "state",
    "on_bt_plotter_clicked",
    "decodeCan",
    "_data",
    "dcodeMsgSg",
    "msg_id",
    "const char*",
    "sg_name",
    "QLCDNumber*",
    "lcd",
    "decodeDIDO",
    "on_NewConnection",
    "on_DisConnection",
    "on_ReadyRead",
    "on_bt_chart_clicked",
    "on_DI_checkBox_clicked",
    "checked",
    "on_DO_checkBox_clicked",
    "on_Address_lineEdit_textChanged",
    "arg1"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[74];
    char stringdata0[11];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[21];
    char stringdata5[19];
    char stringdata6[21];
    char stringdata7[23];
    char stringdata8[39];
    char stringdata9[6];
    char stringdata10[28];
    char stringdata11[28];
    char stringdata12[28];
    char stringdata13[20];
    char stringdata14[13];
    char stringdata15[8];
    char stringdata16[8];
    char stringdata17[6];
    char stringdata18[22];
    char stringdata19[10];
    char stringdata20[6];
    char stringdata21[11];
    char stringdata22[7];
    char stringdata23[12];
    char stringdata24[8];
    char stringdata25[12];
    char stringdata26[4];
    char stringdata27[11];
    char stringdata28[17];
    char stringdata29[17];
    char stringdata30[13];
    char stringdata31[20];
    char stringdata32[23];
    char stringdata33[8];
    char stringdata34[23];
    char stringdata35[32];
    char stringdata36[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 17),  // "on_bt_msg_clicked"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 26),  // "on_bt_del_lastline_clicked"
        QT_MOC_LITERAL(57, 20),  // "on_bt_signal_clicked"
        QT_MOC_LITERAL(78, 18),  // "on_bt_save_clicked"
        QT_MOC_LITERAL(97, 20),  // "on_bt_addDBC_clicked"
        QT_MOC_LITERAL(118, 22),  // "on_bt_FileOpen_clicked"
        QT_MOC_LITERAL(141, 38),  // "on_sg_select_combo_currentInd..."
        QT_MOC_LITERAL(180, 5),  // "index"
        QT_MOC_LITERAL(186, 27),  // "on_pushButton_mode1_clicked"
        QT_MOC_LITERAL(214, 27),  // "on_pushButton_mode2_clicked"
        QT_MOC_LITERAL(242, 27),  // "on_pushButton_close_clicked"
        QT_MOC_LITERAL(270, 19),  // "on_bt_Clear_clicked"
        QT_MOC_LITERAL(290, 12),  // "setDIChannel"
        QT_MOC_LITERAL(303, 7),  // "QLabel*"
        QT_MOC_LITERAL(311, 7),  // "channel"
        QT_MOC_LITERAL(319, 5),  // "state"
        QT_MOC_LITERAL(325, 21),  // "on_bt_plotter_clicked"
        QT_MOC_LITERAL(347, 9),  // "decodeCan"
        QT_MOC_LITERAL(357, 5),  // "_data"
        QT_MOC_LITERAL(363, 10),  // "dcodeMsgSg"
        QT_MOC_LITERAL(374, 6),  // "msg_id"
        QT_MOC_LITERAL(381, 11),  // "const char*"
        QT_MOC_LITERAL(393, 7),  // "sg_name"
        QT_MOC_LITERAL(401, 11),  // "QLCDNumber*"
        QT_MOC_LITERAL(413, 3),  // "lcd"
        QT_MOC_LITERAL(417, 10),  // "decodeDIDO"
        QT_MOC_LITERAL(428, 16),  // "on_NewConnection"
        QT_MOC_LITERAL(445, 16),  // "on_DisConnection"
        QT_MOC_LITERAL(462, 12),  // "on_ReadyRead"
        QT_MOC_LITERAL(475, 19),  // "on_bt_chart_clicked"
        QT_MOC_LITERAL(495, 22),  // "on_DI_checkBox_clicked"
        QT_MOC_LITERAL(518, 7),  // "checked"
        QT_MOC_LITERAL(526, 22),  // "on_DO_checkBox_clicked"
        QT_MOC_LITERAL(549, 31),  // "on_Address_lineEdit_textChanged"
        QT_MOC_LITERAL(581, 4)   // "arg1"
    },
    "MainWindow",
    "on_bt_msg_clicked",
    "",
    "on_bt_del_lastline_clicked",
    "on_bt_signal_clicked",
    "on_bt_save_clicked",
    "on_bt_addDBC_clicked",
    "on_bt_FileOpen_clicked",
    "on_sg_select_combo_currentIndexChanged",
    "index",
    "on_pushButton_mode1_clicked",
    "on_pushButton_mode2_clicked",
    "on_pushButton_close_clicked",
    "on_bt_Clear_clicked",
    "setDIChannel",
    "QLabel*",
    "channel",
    "state",
    "on_bt_plotter_clicked",
    "decodeCan",
    "_data",
    "dcodeMsgSg",
    "msg_id",
    "const char*",
    "sg_name",
    "QLCDNumber*",
    "lcd",
    "decodeDIDO",
    "on_NewConnection",
    "on_DisConnection",
    "on_ReadyRead",
    "on_bt_chart_clicked",
    "on_DI_checkBox_clicked",
    "checked",
    "on_DO_checkBox_clicked",
    "on_Address_lineEdit_textChanged",
    "arg1"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x08,    1 /* Private */,
       3,    0,  153,    2, 0x08,    2 /* Private */,
       4,    0,  154,    2, 0x08,    3 /* Private */,
       5,    0,  155,    2, 0x08,    4 /* Private */,
       6,    0,  156,    2, 0x08,    5 /* Private */,
       7,    0,  157,    2, 0x08,    6 /* Private */,
       8,    1,  158,    2, 0x08,    7 /* Private */,
      10,    0,  161,    2, 0x08,    9 /* Private */,
      11,    0,  162,    2, 0x08,   10 /* Private */,
      12,    0,  163,    2, 0x08,   11 /* Private */,
      13,    0,  164,    2, 0x08,   12 /* Private */,
      14,    2,  165,    2, 0x08,   13 /* Private */,
      18,    0,  170,    2, 0x08,   16 /* Private */,
      19,    1,  171,    2, 0x08,   17 /* Private */,
      21,    4,  174,    2, 0x08,   19 /* Private */,
      27,    1,  183,    2, 0x08,   24 /* Private */,
      28,    0,  186,    2, 0x08,   26 /* Private */,
      29,    0,  187,    2, 0x08,   27 /* Private */,
      30,    0,  188,    2, 0x08,   28 /* Private */,
      31,    0,  189,    2, 0x08,   29 /* Private */,
      32,    1,  190,    2, 0x08,   30 /* Private */,
      34,    1,  193,    2, 0x08,   32 /* Private */,
      35,    1,  196,    2, 0x08,   34 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Bool,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Double, QMetaType::Int, 0x80000000 | 23, QMetaType::QString, 0x80000000 | 25,   22,   24,   20,   26,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::QString,   36,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_bt_msg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_del_lastline_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_signal_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_addDBC_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_FileOpen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sg_select_combo_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_mode1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_mode2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_close_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_Clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setDIChannel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLabel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_bt_plotter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'decodeCan'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'dcodeMsgSg'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLCDNumber *, std::false_type>,
        // method 'decodeDIDO'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_NewConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DisConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_chart_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DI_checkBox_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_DO_checkBox_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_Address_lineEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_bt_msg_clicked(); break;
        case 1: _t->on_bt_del_lastline_clicked(); break;
        case 2: _t->on_bt_signal_clicked(); break;
        case 3: _t->on_bt_save_clicked(); break;
        case 4: _t->on_bt_addDBC_clicked(); break;
        case 5: _t->on_bt_FileOpen_clicked(); break;
        case 6: _t->on_sg_select_combo_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_pushButton_mode1_clicked(); break;
        case 8: _t->on_pushButton_mode2_clicked(); break;
        case 9: _t->on_pushButton_close_clicked(); break;
        case 10: _t->on_bt_Clear_clicked(); break;
        case 11: _t->setDIChannel((*reinterpret_cast< std::add_pointer_t<QLabel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 12: _t->on_bt_plotter_clicked(); break;
        case 13: _t->decodeCan((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: { double _r = _t->dcodeMsgSg((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QLCDNumber*>>(_a[4])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->decodeDIDO((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->on_NewConnection(); break;
        case 17: _t->on_DisConnection(); break;
        case 18: _t->on_ReadyRead(); break;
        //case 19: _t->on_bt_chart_clicked(); break;
        case 20: _t->on_DI_checkBox_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_DO_checkBox_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: _t->on_Address_lineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLCDNumber* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP

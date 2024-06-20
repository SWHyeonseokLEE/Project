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
    "on_bt_OpenDBC_clicked",
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
    uint offsetsAndSizes[72];
    char stringdata0[11];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[21];
    char stringdata5[19];
    char stringdata6[21];
    char stringdata7[22];
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
    char stringdata18[10];
    char stringdata19[6];
    char stringdata20[11];
    char stringdata21[7];
    char stringdata22[12];
    char stringdata23[8];
    char stringdata24[12];
    char stringdata25[4];
    char stringdata26[11];
    char stringdata27[17];
    char stringdata28[17];
    char stringdata29[13];
    char stringdata30[20];
    char stringdata31[23];
    char stringdata32[8];
    char stringdata33[23];
    char stringdata34[32];
    char stringdata35[5];
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
        QT_MOC_LITERAL(118, 21),  // "on_bt_OpenDBC_clicked"
        QT_MOC_LITERAL(140, 38),  // "on_sg_select_combo_currentInd..."
        QT_MOC_LITERAL(179, 5),  // "index"
        QT_MOC_LITERAL(185, 27),  // "on_pushButton_mode1_clicked"
        QT_MOC_LITERAL(213, 27),  // "on_pushButton_mode2_clicked"
        QT_MOC_LITERAL(241, 27),  // "on_pushButton_close_clicked"
        QT_MOC_LITERAL(269, 19),  // "on_bt_Clear_clicked"
        QT_MOC_LITERAL(289, 12),  // "setDIChannel"
        QT_MOC_LITERAL(302, 7),  // "QLabel*"
        QT_MOC_LITERAL(310, 7),  // "channel"
        QT_MOC_LITERAL(318, 5),  // "state"
        QT_MOC_LITERAL(324, 9),  // "decodeCan"
        QT_MOC_LITERAL(334, 5),  // "_data"
        QT_MOC_LITERAL(340, 10),  // "dcodeMsgSg"
        QT_MOC_LITERAL(351, 6),  // "msg_id"
        QT_MOC_LITERAL(358, 11),  // "const char*"
        QT_MOC_LITERAL(370, 7),  // "sg_name"
        QT_MOC_LITERAL(378, 11),  // "QLCDNumber*"
        QT_MOC_LITERAL(390, 3),  // "lcd"
        QT_MOC_LITERAL(394, 10),  // "decodeDIDO"
        QT_MOC_LITERAL(405, 16),  // "on_NewConnection"
        QT_MOC_LITERAL(422, 16),  // "on_DisConnection"
        QT_MOC_LITERAL(439, 12),  // "on_ReadyRead"
        QT_MOC_LITERAL(452, 19),  // "on_bt_chart_clicked"
        QT_MOC_LITERAL(472, 22),  // "on_DI_checkBox_clicked"
        QT_MOC_LITERAL(495, 7),  // "checked"
        QT_MOC_LITERAL(503, 22),  // "on_DO_checkBox_clicked"
        QT_MOC_LITERAL(526, 31),  // "on_Address_lineEdit_textChanged"
        QT_MOC_LITERAL(558, 4)   // "arg1"
    },
    "MainWindow",
    "on_bt_msg_clicked",
    "",
    "on_bt_del_lastline_clicked",
    "on_bt_signal_clicked",
    "on_bt_save_clicked",
    "on_bt_addDBC_clicked",
    "on_bt_OpenDBC_clicked",
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
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  146,    2, 0x08,    1 /* Private */,
       3,    0,  147,    2, 0x08,    2 /* Private */,
       4,    0,  148,    2, 0x08,    3 /* Private */,
       5,    0,  149,    2, 0x08,    4 /* Private */,
       6,    0,  150,    2, 0x08,    5 /* Private */,
       7,    0,  151,    2, 0x08,    6 /* Private */,
       8,    1,  152,    2, 0x08,    7 /* Private */,
      10,    0,  155,    2, 0x08,    9 /* Private */,
      11,    0,  156,    2, 0x08,   10 /* Private */,
      12,    0,  157,    2, 0x08,   11 /* Private */,
      13,    0,  158,    2, 0x08,   12 /* Private */,
      14,    2,  159,    2, 0x08,   13 /* Private */,
      18,    1,  164,    2, 0x08,   16 /* Private */,
      20,    4,  167,    2, 0x08,   18 /* Private */,
      26,    1,  176,    2, 0x08,   23 /* Private */,
      27,    0,  179,    2, 0x08,   25 /* Private */,
      28,    0,  180,    2, 0x08,   26 /* Private */,
      29,    0,  181,    2, 0x08,   27 /* Private */,
      30,    0,  182,    2, 0x08,   28 /* Private */,
      31,    1,  183,    2, 0x08,   29 /* Private */,
      33,    1,  186,    2, 0x08,   31 /* Private */,
      34,    1,  189,    2, 0x08,   33 /* Private */,

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
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Double, QMetaType::Int, 0x80000000 | 22, QMetaType::QString, 0x80000000 | 24,   21,   23,   19,   25,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::QString,   35,

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
        // method 'on_bt_OpenDBC_clicked'
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
        case 5: _t->on_bt_OpenDBC_clicked(); break;
        case 6: _t->on_sg_select_combo_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_pushButton_mode1_clicked(); break;
        case 8: _t->on_pushButton_mode2_clicked(); break;
        case 9: _t->on_pushButton_close_clicked(); break;
        case 10: _t->on_bt_Clear_clicked(); break;
        case 11: _t->setDIChannel((*reinterpret_cast< std::add_pointer_t<QLabel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 12: _t->decodeCan((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: { double _r = _t->dcodeMsgSg((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QLCDNumber*>>(_a[4])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->decodeDIDO((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->on_NewConnection(); break;
        case 16: _t->on_DisConnection(); break;
        case 17: _t->on_ReadyRead(); break;
        case 18: _t->on_bt_chart_clicked(); break;
        case 19: _t->on_DI_checkBox_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_DO_checkBox_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_Address_lineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
        case 13:
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP

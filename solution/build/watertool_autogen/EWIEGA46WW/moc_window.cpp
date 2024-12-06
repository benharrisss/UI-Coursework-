/****************************************************************************
** Meta object code from reading C++ file 'window.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../window.hpp"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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
struct qt_meta_stringdata_CLASSWaterWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWaterWindowENDCLASS = QtMocHelpers::stringData(
    "WaterWindow",
    "setDataLocation",
    "",
    "openCSV",
    "displayStats",
    "about",
    "createPOPs",
    "createTest"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWaterWindowENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[13];
    char stringdata5[6];
    char stringdata6[11];
    char stringdata7[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWaterWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWaterWindowENDCLASS_t qt_meta_stringdata_CLASSWaterWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "WaterWindow"
        QT_MOC_LITERAL(12, 15),  // "setDataLocation"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 7),  // "openCSV"
        QT_MOC_LITERAL(37, 12),  // "displayStats"
        QT_MOC_LITERAL(50, 5),  // "about"
        QT_MOC_LITERAL(56, 10),  // "createPOPs"
        QT_MOC_LITERAL(67, 10)   // "createTest"
    },
    "WaterWindow",
    "setDataLocation",
    "",
    "openCSV",
    "displayStats",
    "about",
    "createPOPs",
    "createTest"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWaterWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject WaterWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSWaterWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWaterWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWaterWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WaterWindow, std::true_type>,
        // method 'setDataLocation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openCSV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayStats'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'about'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createPOPs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void WaterWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WaterWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDataLocation(); break;
        case 1: _t->openCSV(); break;
        case 2: _t->displayStats(); break;
        case 3: _t->about(); break;
        case 4: _t->createPOPs(); break;
        case 5: _t->createTest(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *WaterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WaterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWaterWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WaterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP

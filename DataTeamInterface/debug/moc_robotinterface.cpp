/****************************************************************************
** Meta object code from reading C++ file 'robotinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../robotinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotInterface_t {
    QByteArrayData data[11];
    char stringdata[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotInterface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotInterface_t qt_meta_stringdata_RobotInterface = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 22),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 23),
QT_MOC_LITERAL(4, 63, 27),
QT_MOC_LITERAL(5, 91, 27),
QT_MOC_LITERAL(6, 119, 24),
QT_MOC_LITERAL(7, 144, 26),
QT_MOC_LITERAL(8, 171, 22),
QT_MOC_LITERAL(9, 194, 25),
QT_MOC_LITERAL(10, 220, 11)
    },
    "RobotInterface\0slotOnGpsDataAvailable\0"
    "\0slotOnGyroDataAvailable\0"
    "slotOnActuatorDataAvailable\0"
    "slotOnAcceleroDataAvailable\0"
    "slotOnLidarDataAvailable\0"
    "slotOnMagnetoDataAvailable\0"
    "slotOnOdoDataAvailable\0slotOnRemoteDataAvailable\0"
    "slotTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RobotInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotInterface *_t = static_cast<RobotInterface *>(_o);
        switch (_id) {
        case 0: _t->slotOnGpsDataAvailable(); break;
        case 1: _t->slotOnGyroDataAvailable(); break;
        case 2: _t->slotOnActuatorDataAvailable(); break;
        case 3: _t->slotOnAcceleroDataAvailable(); break;
        case 4: _t->slotOnLidarDataAvailable(); break;
        case 5: _t->slotOnMagnetoDataAvailable(); break;
        case 6: _t->slotOnOdoDataAvailable(); break;
        case 7: _t->slotOnRemoteDataAvailable(); break;
        case 8: _t->slotTimeOut(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RobotInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RobotInterface.data,
      qt_meta_data_RobotInterface,  qt_static_metacall, 0, 0}
};


const QMetaObject *RobotInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RobotInterface.stringdata))
        return static_cast<void*>(const_cast< RobotInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int RobotInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

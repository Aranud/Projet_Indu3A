/****************************************************************************
** Meta object code from reading C++ file 'tcpconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TCPConnection_t {
    QByteArrayData data[10];
    char stringdata[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPConnection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPConnection_t qt_meta_stringdata_TCPConnection = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 9),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 12),
QT_MOC_LITERAL(4, 38, 22),
QT_MOC_LITERAL(5, 61, 11),
QT_MOC_LITERAL(6, 73, 14),
QT_MOC_LITERAL(7, 88, 14),
QT_MOC_LITERAL(8, 103, 13),
QT_MOC_LITERAL(9, 117, 13)
    },
    "TCPConnection\0Connected\0\0Disconnected\0"
    "DataReceivedFromServer\0OnConnected\0"
    "OnDisconnected\0OnDataReceived\0"
    "OnDataWritten\0p_iDataLength"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,

       0        // eod
};

void TCPConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TCPConnection *_t = static_cast<TCPConnection *>(_o);
        switch (_id) {
        case 0: _t->Connected(); break;
        case 1: _t->Disconnected(); break;
        case 2: _t->DataReceivedFromServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->OnConnected(); break;
        case 4: _t->OnDisconnected(); break;
        case 5: _t->OnDataReceived(); break;
        case 6: _t->OnDataWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TCPConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPConnection::Connected)) {
                *result = 0;
            }
        }
        {
            typedef void (TCPConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPConnection::Disconnected)) {
                *result = 1;
            }
        }
        {
            typedef void (TCPConnection::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPConnection::DataReceivedFromServer)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject TCPConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPConnection.data,
      qt_meta_data_TCPConnection,  qt_static_metacall, 0, 0}
};


const QMetaObject *TCPConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TCPConnection.stringdata))
        return static_cast<void*>(const_cast< TCPConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int TCPConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TCPConnection::Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TCPConnection::Disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TCPConnection::DataReceivedFromServer(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

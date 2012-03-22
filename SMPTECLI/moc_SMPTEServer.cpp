/****************************************************************************
** Meta object code from reading C++ file 'SMPTEServer.hpp'
**
** Created: Thu Mar 22 23:42:11 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SMPTEServer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SMPTEServer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SMPTEServer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   13,   12,   12, 0x0a,
      65,   60,   12,   12, 0x0a,
      83,   12,   12,   12, 0x08,
      99,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SMPTEServer[] = {
    "SMPTEServer\0\0timestamp,goal\0"
    "sendTimeInfo(QVariant,QVariant)\0goal\0"
    "setGoal(QVariant)\0newConnection()\0"
    "connectionDisconnected()\0"
};

const QMetaObject SMPTEServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SMPTEServer,
      qt_meta_data_SMPTEServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SMPTEServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SMPTEServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SMPTEServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SMPTEServer))
        return static_cast<void*>(const_cast< SMPTEServer*>(this));
    return QObject::qt_metacast(_clname);
}

int SMPTEServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendTimeInfo((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: setGoal((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: newConnection(); break;
        case 3: connectionDisconnected(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

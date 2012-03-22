/****************************************************************************
** Meta object code from reading C++ file 'jltcinterface.h'
**
** Created: Thu Mar 22 23:30:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "jltcinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jltcinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SmpteLTCDecodeInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   25,   24,   24, 0x05,
      64,   54,   24,   24, 0x05,
      96,   25,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     114,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SmpteLTCDecodeInterface[] = {
    "SmpteLTCDecodeInterface\0\0time\0"
    "timeRecieved(SMPTETime)\0time,goal\0"
    "timeRecieved(QVariant,QVariant)\0"
    "timeRecieved(int)\0readyRead()\0"
};

const QMetaObject SmpteLTCDecodeInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SmpteLTCDecodeInterface,
      qt_meta_data_SmpteLTCDecodeInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SmpteLTCDecodeInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SmpteLTCDecodeInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SmpteLTCDecodeInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SmpteLTCDecodeInterface))
        return static_cast<void*>(const_cast< SmpteLTCDecodeInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int SmpteLTCDecodeInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timeRecieved((*reinterpret_cast< SMPTETime(*)>(_a[1]))); break;
        case 1: timeRecieved((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 2: timeRecieved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: readyRead(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SmpteLTCDecodeInterface::timeRecieved(SMPTETime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SmpteLTCDecodeInterface::timeRecieved(QVariant _t1, QVariant _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SmpteLTCDecodeInterface::timeRecieved(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

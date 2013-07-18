/****************************************************************************
** Meta object code from reading C++ file 'bouton.h'
**
** Created: Thu Mar 1 14:17:11 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qlivre_dialogues/bouton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bouton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Bouton[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,    8,    7,    7, 0x0a,
      34,    7,   30,    7, 0x0a,
      43,    7,   30,    7, 0x0a,
      47,    7,   30,    7, 0x0a,
      53,   51,    7,    7, 0x0a,
      65,   63,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Bouton[] = {
    "Bouton\0\0valeur\0setValeur(int)\0int\0"
    "valeur()\0x()\0y()\0x\0setX(int)\0y\0setY(int)\0"
};

const QMetaObject Bouton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_Bouton,
      qt_meta_data_Bouton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Bouton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Bouton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Bouton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bouton))
        return static_cast<void*>(const_cast< Bouton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int Bouton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setValeur((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { int _r = valeur();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = x();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = y();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: setX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: setY((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

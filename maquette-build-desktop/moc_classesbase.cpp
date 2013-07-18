/****************************************************************************
** Meta object code from reading C++ file 'classesbase.h'
**
** Created: Fri Feb 24 13:38:38 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../maquette/classesbase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classesbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AfficherTexte[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AfficherTexte[] = {
    "AfficherTexte\0\0s\0affichetxt(string)\0"
};

const QMetaObject AfficherTexte::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AfficherTexte,
      qt_meta_data_AfficherTexte, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AfficherTexte::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AfficherTexte::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AfficherTexte::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AfficherTexte))
        return static_cast<void*>(const_cast< AfficherTexte*>(this));
    return QWidget::qt_metacast(_clname);
}

int AfficherTexte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: affichetxt((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AfficherDe[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   11,   12,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AfficherDe[] = {
    "AfficherDe\0\0AfficherDe*\0affichede()\0"
};

const QMetaObject AfficherDe::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AfficherDe,
      qt_meta_data_AfficherDe, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AfficherDe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AfficherDe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AfficherDe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AfficherDe))
        return static_cast<void*>(const_cast< AfficherDe*>(this));
    return QWidget::qt_metacast(_clname);
}

int AfficherDe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { AfficherDe* _r = affichede();
            if (_a[0]) *reinterpret_cast< AfficherDe**>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AfficherRegles[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   15,   16,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AfficherRegles[] = {
    "AfficherRegles\0\0AfficherTexte*\0"
    "ouvrirDialogue()\0"
};

const QMetaObject AfficherRegles::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AfficherRegles,
      qt_meta_data_AfficherRegles, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AfficherRegles::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AfficherRegles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AfficherRegles::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AfficherRegles))
        return static_cast<void*>(const_cast< AfficherRegles*>(this));
    return QWidget::qt_metacast(_clname);
}

int AfficherRegles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { AfficherTexte* _r = ouvrirDialogue();
            if (_a[0]) *reinterpret_cast< AfficherTexte**>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AfficherMenu[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   13,   14,   13, 0x0a,
      31,   13,   14,   13, 0x0a,
      50,   13,   14,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AfficherMenu[] = {
    "AfficherMenu\0\0int\0ouvrirMenu()\0"
    "ouvrirMenuDepart()\0choisiremplacement()\0"
};

const QMetaObject AfficherMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AfficherMenu,
      qt_meta_data_AfficherMenu, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AfficherMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AfficherMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AfficherMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AfficherMenu))
        return static_cast<void*>(const_cast< AfficherMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int AfficherMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = ouvrirMenu();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = ouvrirMenuDepart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = choisiremplacement();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

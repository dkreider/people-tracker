/****************************************************************************
** Meta object code from reading C++ file 'peopletracker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PeopleTracker/peopletracker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'peopletracker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_peopleTracker_t {
    QByteArrayData data[16];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_peopleTracker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_peopleTracker_t qt_meta_stringdata_peopleTracker = {
    {
QT_MOC_LITERAL(0, 0, 13), // "peopleTracker"
QT_MOC_LITERAL(1, 14, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(4, 60, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(5, 84, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(6, 108, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(7, 133, 33), // "on_actionLoad_customers_trigg..."
QT_MOC_LITERAL(8, 167, 19), // "on_listView_clicked"
QT_MOC_LITERAL(9, 187, 5), // "index"
QT_MOC_LITERAL(10, 193, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(11, 217, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(12, 242, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(13, 268, 28), // "on_actionFind_name_triggered"
QT_MOC_LITERAL(14, 297, 23), // "on_saveButton_2_clicked"
QT_MOC_LITERAL(15, 321, 23) // "on_updateButton_clicked"

    },
    "peopleTracker\0on_clearButton_clicked\0"
    "\0on_saveButton_clicked\0on_deleteButton_clicked\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionLoad_customers_triggered\0"
    "on_listView_clicked\0index\0"
    "on_actionSave_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionDelete_triggered\0"
    "on_actionFind_name_triggered\0"
    "on_saveButton_2_clicked\0on_updateButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_peopleTracker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void peopleTracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        peopleTracker *_t = static_cast<peopleTracker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_clearButton_clicked(); break;
        case 1: _t->on_saveButton_clicked(); break;
        case 2: _t->on_deleteButton_clicked(); break;
        case 3: _t->on_actionExit_triggered(); break;
        case 4: _t->on_actionAbout_triggered(); break;

        case 6: { QString _r = _t->on_listView_clicked();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: _t->on_listView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_actionSave_triggered(); break;
        case 9: _t->on_actionClose_triggered(); break;
        case 10: _t->on_actionDelete_triggered(); break;
        case 11: _t->on_actionFind_name_triggered(); break;

        case 13: _t->on_updateButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject peopleTracker::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_peopleTracker.data,
      qt_meta_data_peopleTracker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *peopleTracker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *peopleTracker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_peopleTracker.stringdata0))
        return static_cast<void*>(const_cast< peopleTracker*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int peopleTracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

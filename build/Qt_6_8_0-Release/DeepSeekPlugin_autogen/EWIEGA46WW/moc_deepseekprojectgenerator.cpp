/****************************************************************************
** Meta object code from reading C++ file 'deepseekprojectgenerator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../deepseekprojectgenerator.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepseekprojectgenerator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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
struct qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekProjectGeneratorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekProjectGeneratorENDCLASS = QtMocHelpers::stringData(
    "DeepSeekAI::Internal::DeepSeekProjectGenerator",
    "projectGenerated",
    "",
    "projectPath",
    "projectOpened",
    "ProjectExplorer::Project*",
    "project",
    "projectAnalysisComplete",
    "QMap<QString,QString>",
    "fileContents",
    "optimizationComplete",
    "optimizedFiles",
    "errorOccurred",
    "error",
    "BuildSystem",
    "CMake",
    "QMake",
    "Qbs"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekProjectGeneratorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       1,   59, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    2 /* Public */,
       4,    1,   47,    2, 0x06,    4 /* Public */,
       7,    1,   50,    2, 0x06,    6 /* Public */,
      10,    1,   53,    2, 0x06,    8 /* Public */,
      12,    1,   56,    2, 0x06,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,   11,
    QMetaType::Void, QMetaType::QString,   13,

 // enums: name, alias, flags, count, data
      14,   14, 0x0,    3,   64,

 // enum data: key, value
      15, uint(DeepSeekAI::Internal::DeepSeekProjectGenerator::CMake),
      16, uint(DeepSeekAI::Internal::DeepSeekProjectGenerator::QMake),
      17, uint(DeepSeekAI::Internal::DeepSeekProjectGenerator::Qbs),

       0        // eod
};

Q_CONSTINIT const QMetaObject DeepSeekAI::Internal::DeepSeekProjectGenerator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekProjectGeneratorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekProjectGeneratorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekProjectGeneratorENDCLASS_t,
        // enum 'BuildSystem'
        QtPrivate::TypeAndForceComplete<DeepSeekProjectGenerator::BuildSystem, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeepSeekProjectGenerator, std::true_type>,
        // method 'projectGenerated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'projectOpened'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ProjectExplorer::Project *, std::false_type>,
        // method 'projectAnalysisComplete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<QString,QString> &, std::false_type>,
        // method 'optimizationComplete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<QString,QString> &, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void DeepSeekAI::Internal::DeepSeekProjectGenerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeepSeekProjectGenerator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->projectGenerated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->projectOpened((*reinterpret_cast< std::add_pointer_t<ProjectExplorer::Project*>>(_a[1]))); break;
        case 2: _t->projectAnalysisComplete((*reinterpret_cast< std::add_pointer_t<QMap<QString,QString>>>(_a[1]))); break;
        case 3: _t->optimizationComplete((*reinterpret_cast< std::add_pointer_t<QMap<QString,QString>>>(_a[1]))); break;
        case 4: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ProjectExplorer::Project* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeepSeekProjectGenerator::*)(const QString & );
            if (_t _q_method = &DeepSeekProjectGenerator::projectGenerated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeepSeekProjectGenerator::*)(ProjectExplorer::Project * );
            if (_t _q_method = &DeepSeekProjectGenerator::projectOpened; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeepSeekProjectGenerator::*)(const QMap<QString,QString> & );
            if (_t _q_method = &DeepSeekProjectGenerator::projectAnalysisComplete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DeepSeekProjectGenerator::*)(const QMap<QString,QString> & );
            if (_t _q_method = &DeepSeekProjectGenerator::optimizationComplete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DeepSeekProjectGenerator::*)(const QString & );
            if (_t _q_method = &DeepSeekProjectGenerator::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *DeepSeekAI::Internal::DeepSeekProjectGenerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepSeekAI::Internal::DeepSeekProjectGenerator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekProjectGeneratorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeepSeekAI::Internal::DeepSeekProjectGenerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DeepSeekAI::Internal::DeepSeekProjectGenerator::projectGenerated(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeepSeekAI::Internal::DeepSeekProjectGenerator::projectOpened(ProjectExplorer::Project * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeepSeekAI::Internal::DeepSeekProjectGenerator::projectAnalysisComplete(const QMap<QString,QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DeepSeekAI::Internal::DeepSeekProjectGenerator::optimizationComplete(const QMap<QString,QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DeepSeekAI::Internal::DeepSeekProjectGenerator::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP

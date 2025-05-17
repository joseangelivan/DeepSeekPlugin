/****************************************************************************
** Meta object code from reading C++ file 'deepseekwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../deepseekwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepseekwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekWidgetENDCLASS = QtMocHelpers::stringData(
    "DeepSeekAI::Internal::DeepSeekWidget",
    "requestGenerated",
    "",
    "prompt",
    "mode",
    "requestFixCode",
    "code",
    "description",
    "requestProjectGeneration",
    "projectName",
    "projectPath",
    "DeepSeekProjectGenerator::BuildSystem",
    "buildSystem",
    "projectType",
    "onResponseReceived",
    "response",
    "onErrorOccurred",
    "error",
    "onProgressChanged",
    "progress",
    "onProjectGenerated",
    "onSettingsChanged",
    "apiKeyValid",
    "handleAnalysisResults",
    "results",
    "onGenerateCodeClicked",
    "onFixCodeClicked",
    "onGenerateProjectClicked",
    "onBuildSystemChanged",
    "index"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   92,    2, 0x06,    1 /* Public */,
       5,    2,   97,    2, 0x06,    4 /* Public */,
       8,    5,  102,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,  113,    2, 0x0a,   13 /* Public */,
      16,    1,  116,    2, 0x0a,   15 /* Public */,
      18,    1,  119,    2, 0x0a,   17 /* Public */,
      20,    1,  122,    2, 0x0a,   19 /* Public */,
      21,    1,  125,    2, 0x0a,   21 /* Public */,
      23,    1,  128,    2, 0x0a,   23 /* Public */,
      25,    0,  131,    2, 0x08,   25 /* Private */,
      26,    0,  132,    2, 0x08,   26 /* Private */,
      27,    0,  133,    2, 0x08,   27 /* Private */,
      28,    1,  134,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 11, QMetaType::QString, QMetaType::QString,    9,   10,   12,   13,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::QJsonObject,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,

       0        // eod
};

Q_CONSTINIT const QMetaObject DeepSeekAI::Internal::DeepSeekWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeepSeekWidget, std::true_type>,
        // method 'requestGenerated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'requestFixCode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'requestProjectGeneration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<DeepSeekProjectGenerator::BuildSystem, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onResponseReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onErrorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onProgressChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onProjectGenerated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSettingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handleAnalysisResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'onGenerateCodeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFixCodeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGenerateProjectClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onBuildSystemChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void DeepSeekAI::Internal::DeepSeekWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeepSeekWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->requestGenerated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->requestFixCode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->requestProjectGeneration((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<DeepSeekProjectGenerator::BuildSystem>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 3: _t->onResponseReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->onErrorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->onProgressChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->onProjectGenerated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->onSettingsChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->handleAnalysisResults((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 9: _t->onGenerateCodeClicked(); break;
        case 10: _t->onFixCodeClicked(); break;
        case 11: _t->onGenerateProjectClicked(); break;
        case 12: _t->onBuildSystemChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeepSeekWidget::*)(const QString & , const QString & );
            if (_t _q_method = &DeepSeekWidget::requestGenerated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeepSeekWidget::*)(const QString & , const QString & );
            if (_t _q_method = &DeepSeekWidget::requestFixCode; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeepSeekWidget::*)(const QString & , const QString & , DeepSeekProjectGenerator::BuildSystem , const QString & , const QString & );
            if (_t _q_method = &DeepSeekWidget::requestProjectGeneration; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *DeepSeekAI::Internal::DeepSeekWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepSeekAI::Internal::DeepSeekWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DeepSeekAI::Internal::DeepSeekWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void DeepSeekAI::Internal::DeepSeekWidget::requestGenerated(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeepSeekAI::Internal::DeepSeekWidget::requestFixCode(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeepSeekAI::Internal::DeepSeekWidget::requestProjectGeneration(const QString & _t1, const QString & _t2, DeepSeekProjectGenerator::BuildSystem _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP

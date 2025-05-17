/****************************************************************************
** Meta object code from reading C++ file 'deepseektool.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../deepseektool.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepseektool.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekToolENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekToolENDCLASS = QtMocHelpers::stringData(
    "DeepSeekAI::Internal::DeepSeekTool",
    "responseReceived",
    "",
    "response",
    "fixReady",
    "fixedCode",
    "projectAnalysisReady",
    "analysis",
    "errorOccurred",
    "error",
    "progressChanged",
    "progress",
    "settingsChanged",
    "apiKeyValid",
    "sendRequest",
    "prompt",
    "mode",
    "requestFix",
    "code",
    "problemDescription",
    "requestProjectAnalysis",
    "QMap<QString,QString>",
    "projectContents",
    "onRequestFinished",
    "QNetworkReply*",
    "reply",
    "onSslErrors",
    "QList<QSslError>",
    "errors"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekToolENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    1,   83,    2, 0x06,    3 /* Public */,
       6,    1,   86,    2, 0x06,    5 /* Public */,
       8,    1,   89,    2, 0x06,    7 /* Public */,
      10,    1,   92,    2, 0x06,    9 /* Public */,
      12,    1,   95,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    2,   98,    2, 0x0a,   13 /* Public */,
      17,    2,  103,    2, 0x0a,   16 /* Public */,
      20,    1,  108,    2, 0x0a,   19 /* Public */,
      23,    1,  111,    2, 0x08,   21 /* Private */,
      26,    2,  114,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24, 0x80000000 | 27,   25,   28,

       0        // eod
};

Q_CONSTINIT const QMetaObject DeepSeekAI::Internal::DeepSeekTool::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekToolENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekToolENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekToolENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeepSeekTool, std::true_type>,
        // method 'responseReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'fixReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'projectAnalysisReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'progressChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'settingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sendRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'requestFix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'requestProjectAnalysis'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<QString,QString> &, std::false_type>,
        // method 'onRequestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'onSslErrors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QSslError> &, std::false_type>
    >,
    nullptr
} };

void DeepSeekAI::Internal::DeepSeekTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeepSeekTool *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->responseReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->fixReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->projectAnalysisReady((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 3: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->progressChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->settingsChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->requestFix((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->requestProjectAnalysis((*reinterpret_cast< std::add_pointer_t<QMap<QString,QString>>>(_a[1]))); break;
        case 9: _t->onRequestFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 10: _t->onSslErrors((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeepSeekTool::*)(const QString & );
            if (_t _q_method = &DeepSeekTool::responseReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeepSeekTool::*)(const QString & );
            if (_t _q_method = &DeepSeekTool::fixReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeepSeekTool::*)(const QJsonObject & );
            if (_t _q_method = &DeepSeekTool::projectAnalysisReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DeepSeekTool::*)(const QString & );
            if (_t _q_method = &DeepSeekTool::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DeepSeekTool::*)(int );
            if (_t _q_method = &DeepSeekTool::progressChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DeepSeekTool::*)(bool );
            if (_t _q_method = &DeepSeekTool::settingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *DeepSeekAI::Internal::DeepSeekTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepSeekAI::Internal::DeepSeekTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekToolENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeepSeekAI::Internal::DeepSeekTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DeepSeekAI::Internal::DeepSeekTool::responseReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeepSeekAI::Internal::DeepSeekTool::fixReady(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeepSeekAI::Internal::DeepSeekTool::projectAnalysisReady(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DeepSeekAI::Internal::DeepSeekTool::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DeepSeekAI::Internal::DeepSeekTool::progressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DeepSeekAI::Internal::DeepSeekTool::settingsChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP

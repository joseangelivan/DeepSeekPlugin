/****************************************************************************
** Meta object code from reading C++ file 'deepseekcodeeditor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../deepseekcodeeditor.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepseekcodeeditor.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekCodeEditorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekCodeEditorENDCLASS = QtMocHelpers::stringData(
    "DeepSeekAI::Internal::DeepSeekCodeEditor",
    "editorChanged",
    "",
    "contentChanged",
    "fileSaved",
    "filePath",
    "onEditorChanged",
    "Core::IEditor*",
    "editor"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekCodeEditorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    0,   39,    2, 0x06,    2 /* Public */,
       4,    1,   40,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   43,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject DeepSeekAI::Internal::DeepSeekCodeEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekCodeEditorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekCodeEditorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekCodeEditorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeepSeekCodeEditor, std::true_type>,
        // method 'editorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'contentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fileSaved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onEditorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Core::IEditor *, std::false_type>
    >,
    nullptr
} };

void DeepSeekAI::Internal::DeepSeekCodeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeepSeekCodeEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->editorChanged(); break;
        case 1: _t->contentChanged(); break;
        case 2: _t->fileSaved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->onEditorChanged((*reinterpret_cast< std::add_pointer_t<Core::IEditor*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Core::IEditor* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeepSeekCodeEditor::*)();
            if (_t _q_method = &DeepSeekCodeEditor::editorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeepSeekCodeEditor::*)();
            if (_t _q_method = &DeepSeekCodeEditor::contentChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeepSeekCodeEditor::*)(const QString & );
            if (_t _q_method = &DeepSeekCodeEditor::fileSaved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *DeepSeekAI::Internal::DeepSeekCodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepSeekAI::Internal::DeepSeekCodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekCodeEditorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeepSeekAI::Internal::DeepSeekCodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DeepSeekAI::Internal::DeepSeekCodeEditor::editorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DeepSeekAI::Internal::DeepSeekCodeEditor::contentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DeepSeekAI::Internal::DeepSeekCodeEditor::fileSaved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP

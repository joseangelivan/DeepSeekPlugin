/****************************************************************************
** Meta object code from reading C++ file 'deepseekplugin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../deepseekplugin.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepseekplugin.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekPluginENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekPluginENDCLASS = QtMocHelpers::stringData(
    "DeepSeekAI::Internal::DeepSeekPlugin",
    "showWidget",
    ""
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekPluginENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DeepSeekAI::Internal::DeepSeekPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtensionSystem::IPlugin::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekPluginENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekPluginENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekPluginENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeepSeekPlugin, std::true_type>,
        // method 'showWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DeepSeekAI::Internal::DeepSeekPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeepSeekPlugin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showWidget(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *DeepSeekAI::Internal::DeepSeekPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepSeekAI::Internal::DeepSeekPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeepSeekAISCOPEInternalSCOPEDeepSeekPluginENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return ExtensionSystem::IPlugin::qt_metacast(_clname);
}

int DeepSeekAI::Internal::DeepSeekPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtensionSystem::IPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
using namespace DeepSeekAI;
using namespace DeepSeekAI::Internal;

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_DeepSeekPlugin[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x21,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'Q',  't',  'C', 
    'r',  'e',  'a',  't',  'o',  'r',  'P',  'l', 
    'u',  'g',  'i',  'n', 
    // "className"
    0x03,  0x6e,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  'P',  'l',  'u',  'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xad,  0x68,  'C',  'a',  't',  'e',  'g', 
    'o',  'r',  'y',  0x74,  'Q',  't',  ' ',  'C', 
    'r',  'e',  'a',  't',  'o',  'r',  ':',  ':', 
    'E',  'x',  'a',  'm',  'p',  'l',  'e',  's', 
    0x6d,  'C',  'o',  'm',  'p',  'a',  't',  'V', 
    'e',  'r',  's',  'i',  'o',  'n',  0x65,  '1', 
    '.',  '0',  '.',  '0',  0x69,  'C',  'o',  'p', 
    'y',  'r',  'i',  'g',  'h',  't',  0x76,  '(', 
    'C',  ')',  ' ',  '2',  '0',  '2',  '5',  ' ', 
    'I',  'v',  'a',  'n',  ' ',  'R',  'u',  'b', 
    'i',  'a',  'n',  'e',  's',  0x6c,  'D',  'e', 
    'p',  'e',  'n',  'd',  'e',  'n',  'c',  'i', 
    'e',  's',  0x83,  0xa2,  0x62,  'I',  'd',  0x64, 
    'C',  'o',  'r',  'e',  0x67,  'V',  'e',  'r', 
    's',  'i',  'o',  'n',  0x66,  '1',  '6',  '.', 
    '0',  '.',  '1',  0xa2,  0x62,  'I',  'd',  0x6f, 
    'P',  'r',  'o',  'j',  'e',  'c',  't',  'E', 
    'x',  'p',  'l',  'o',  'r',  'e',  'r',  0x67, 
    'V',  'e',  'r',  's',  'i',  'o',  'n',  0x66, 
    '1',  '6',  '.',  '0',  '.',  '1',  0xa2,  0x62, 
    'I',  'd',  0x6a,  'T',  'e',  'x',  't',  'E', 
    'd',  'i',  't',  'o',  'r',  0x67,  'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x66,  '1',  '6', 
    '.',  '0',  '.',  '1',  0x6b,  'D',  'e',  's', 
    'c',  'r',  'i',  'p',  't',  'i',  'o',  'n', 
    0x78,  0x26,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  ' ',  'A',  'I',  ' ',  'i',  'n', 
    't',  'e',  'g',  'r',  'a',  't',  'i',  'o', 
    'n',  ' ',  'f',  'o',  'r',  ' ',  'Q',  't', 
    ' ',  'C',  'r',  'e',  'a',  't',  'o',  'r', 
    0x62,  'I',  'd',  0x72,  'd',  'e',  'e',  'p', 
    's',  'e',  'e',  'k',  '.',  'a',  'i',  '.', 
    'p',  'l',  'u',  'g',  'i',  'n',  0x67,  'L', 
    'i',  'c',  'e',  'n',  's',  'e',  0x78,  0x26, 
    'G',  'P',  'L',  '-',  '3',  '.',  '0',  '-', 
    'o',  'n',  'l',  'y',  ' ',  'W',  'I',  'T', 
    'H',  ' ',  'Q',  't',  '-',  'G',  'P',  'L', 
    '-',  'e',  'x',  'c',  'e',  'p',  't',  'i', 
    'o',  'n',  '-',  '1',  '.',  '0',  0x64,  'N', 
    'a',  'm',  'e',  0x71,  'D',  'e',  'e',  'p', 
    'S',  'e',  'e',  'k',  'A',  'I',  ' ',  'P', 
    'l',  'u',  'g',  'i',  'n',  0x69,  'P',  'l', 
    'a',  't',  'f',  'o',  'r',  'm',  's',  0x71, 
    'W',  'i',  'n',  'd',  'o',  'w',  's',  ',', 
    'L',  'i',  'n',  'u',  'x',  ',',  'M',  'a', 
    'c',  0x63,  'U',  'r',  'l',  0x78,  0x2f,  'h', 
    't',  't',  'p',  's',  ':',  '/',  '/',  'g', 
    'i',  't',  'h',  'u',  'b',  '.',  'c',  'o', 
    'm',  '/',  'j',  'o',  's',  'e',  'a',  'n', 
    'g',  'e',  'l',  'i',  'v',  'a',  'n',  '/', 
    'D',  'e',  'e',  'p',  'S',  'e',  'e',  'k', 
    'P',  'l',  'u',  'g',  'i',  'n',  0x66,  'V', 
    'e',  'n',  'd',  'o',  'r',  0x6d,  'I',  'v', 
    'a',  'n',  ' ',  'R',  'u',  'b',  'i',  'a', 
    'n',  'e',  's',  0x68,  'V',  'e',  'n',  'd', 
    'o',  'r',  'I',  'd',  0x70,  'd',  'e',  'e', 
    'p',  's',  'e',  'e',  'k',  'a',  'i',  'p', 
    'l',  'u',  'g',  'i',  'n',  0x67,  'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x65,  '1',  '.', 
    '0',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(DeepSeekAI::Internal::DeepSeekPlugin, DeepSeekPlugin, qt_pluginMetaDataV2_DeepSeekPlugin)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_DeepSeekPlugin[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x21,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'Q',  't',  'C', 
    'r',  'e',  'a',  't',  'o',  'r',  'P',  'l', 
    'u',  'g',  'i',  'n', 
    // "className"
    0x03,  0x6e,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  'P',  'l',  'u',  'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xad,  0x68,  'C',  'a',  't',  'e',  'g', 
    'o',  'r',  'y',  0x74,  'Q',  't',  ' ',  'C', 
    'r',  'e',  'a',  't',  'o',  'r',  ':',  ':', 
    'E',  'x',  'a',  'm',  'p',  'l',  'e',  's', 
    0x6d,  'C',  'o',  'm',  'p',  'a',  't',  'V', 
    'e',  'r',  's',  'i',  'o',  'n',  0x65,  '1', 
    '.',  '0',  '.',  '0',  0x69,  'C',  'o',  'p', 
    'y',  'r',  'i',  'g',  'h',  't',  0x76,  '(', 
    'C',  ')',  ' ',  '2',  '0',  '2',  '5',  ' ', 
    'I',  'v',  'a',  'n',  ' ',  'R',  'u',  'b', 
    'i',  'a',  'n',  'e',  's',  0x6c,  'D',  'e', 
    'p',  'e',  'n',  'd',  'e',  'n',  'c',  'i', 
    'e',  's',  0x83,  0xa2,  0x62,  'I',  'd',  0x64, 
    'C',  'o',  'r',  'e',  0x67,  'V',  'e',  'r', 
    's',  'i',  'o',  'n',  0x66,  '1',  '6',  '.', 
    '0',  '.',  '1',  0xa2,  0x62,  'I',  'd',  0x6f, 
    'P',  'r',  'o',  'j',  'e',  'c',  't',  'E', 
    'x',  'p',  'l',  'o',  'r',  'e',  'r',  0x67, 
    'V',  'e',  'r',  's',  'i',  'o',  'n',  0x66, 
    '1',  '6',  '.',  '0',  '.',  '1',  0xa2,  0x62, 
    'I',  'd',  0x6a,  'T',  'e',  'x',  't',  'E', 
    'd',  'i',  't',  'o',  'r',  0x67,  'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x66,  '1',  '6', 
    '.',  '0',  '.',  '1',  0x6b,  'D',  'e',  's', 
    'c',  'r',  'i',  'p',  't',  'i',  'o',  'n', 
    0x78,  0x26,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  ' ',  'A',  'I',  ' ',  'i',  'n', 
    't',  'e',  'g',  'r',  'a',  't',  'i',  'o', 
    'n',  ' ',  'f',  'o',  'r',  ' ',  'Q',  't', 
    ' ',  'C',  'r',  'e',  'a',  't',  'o',  'r', 
    0x62,  'I',  'd',  0x72,  'd',  'e',  'e',  'p', 
    's',  'e',  'e',  'k',  '.',  'a',  'i',  '.', 
    'p',  'l',  'u',  'g',  'i',  'n',  0x67,  'L', 
    'i',  'c',  'e',  'n',  's',  'e',  0x78,  0x26, 
    'G',  'P',  'L',  '-',  '3',  '.',  '0',  '-', 
    'o',  'n',  'l',  'y',  ' ',  'W',  'I',  'T', 
    'H',  ' ',  'Q',  't',  '-',  'G',  'P',  'L', 
    '-',  'e',  'x',  'c',  'e',  'p',  't',  'i', 
    'o',  'n',  '-',  '1',  '.',  '0',  0x64,  'N', 
    'a',  'm',  'e',  0x71,  'D',  'e',  'e',  'p', 
    'S',  'e',  'e',  'k',  'A',  'I',  ' ',  'P', 
    'l',  'u',  'g',  'i',  'n',  0x69,  'P',  'l', 
    'a',  't',  'f',  'o',  'r',  'm',  's',  0x71, 
    'W',  'i',  'n',  'd',  'o',  'w',  's',  ',', 
    'L',  'i',  'n',  'u',  'x',  ',',  'M',  'a', 
    'c',  0x63,  'U',  'r',  'l',  0x78,  0x2f,  'h', 
    't',  't',  'p',  's',  ':',  '/',  '/',  'g', 
    'i',  't',  'h',  'u',  'b',  '.',  'c',  'o', 
    'm',  '/',  'j',  'o',  's',  'e',  'a',  'n', 
    'g',  'e',  'l',  'i',  'v',  'a',  'n',  '/', 
    'D',  'e',  'e',  'p',  'S',  'e',  'e',  'k', 
    'P',  'l',  'u',  'g',  'i',  'n',  0x66,  'V', 
    'e',  'n',  'd',  'o',  'r',  0x6d,  'I',  'v', 
    'a',  'n',  ' ',  'R',  'u',  'b',  'i',  'a', 
    'n',  'e',  's',  0x68,  'V',  'e',  'n',  'd', 
    'o',  'r',  'I',  'd',  0x70,  'd',  'e',  'e', 
    'p',  's',  'e',  'e',  'k',  'a',  'i',  'p', 
    'l',  'u',  'g',  'i',  'n',  0x67,  'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x65,  '1',  '.', 
    '0',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(DeepSeekAI::Internal::DeepSeekPlugin, DeepSeekPlugin)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP

cmake_minimum_required(VERSION 3.16)

# Configurar rutas de Qt Creator
list(APPEND CMAKE_PREFIX_PATH "/opt/qtcreator-16.0.1/bin")



project(DeepSeekPlugin LANGUAGES CXX)

# Configuración básica de CMake
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Buscar Qt6 y sus componentes
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    Network
    Concurrent
    Core5Compat
)


set(QT_CREATOR_QT_DIR "/opt/qtcreator-16.0.1/lib/Qt")
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets PATHS "${QT_CREATOR_QT_DIR}" NO_DEFAULT_PATH)

# Buscar componentes de Qt Creator
find_package(QtCreator REQUIRED COMPONENTS
    Core
    ProjectExplorer
    TextEditor
    Utils
)

# Configuración de recursos
qt_add_resources(DeepSeekPlugin_RESOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/resources/deepseekplugin.qrc"
)


# Definición del plugin
add_qtc_plugin(DeepSeekPlugin
    PLUGIN_DEPENDS
        QtCreator::Core
        QtCreator::ProjectExplorer
        QtCreator::TextEditor
        QtCreator::Utils
    DEPENDS
        Qt6::Widgets
        Qt6::Network
        Qt6::Concurrent
        Qt6::Core5Compat
        QtCreator::ExtensionSystem
    SOURCES
        deepseekplugin.h
        deepseekplugin.cpp
        deepseekwidget.h
        deepseekwidget.cpp
        deepseektool.h
        deepseektool.cpp
        deepseekprojectgenerator.h
        deepseekprojectgenerator.cpp
        deepseekcodeeditor.h
        deepseekcodeeditor.cpp
        deepseekpluginconstants.h
        deepseekplugintr.h
        deepseeksettingsdialog.h
        deepseeksettingsdialog.cpp
        deepseeksettingsdialog.ui
        messagehelper.h
        ${DeepSeekPlugin_RESOURCES}
)

# Configuración de metadatos
set_target_properties(DeepSeekPlugin PROPERTIES
    QT_PLUGIN_CLASS_NAME "DeepSeekPlugin"
    QT_PLUGIN_METADATA_FILE "${CMAKE_CURRENT_SOURCE_DIR}/DeepSeekPlugin.json.in"
    QT_PLUGIN_METADATA_DEPENDENCIES "Core,1600100;ProjectExplorer,1600100;TextEditor,1600100;Utils,1600100"
)
# Incluir directorios necesarios
target_include_directories(DeepSeekPlugin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Qt6Widgets_INCLUDE_DIRS}
)

# Configuración para ejecutar Qt Creator
get_target_property(QtCreatorCorePath QtCreator::Core LOCATION)
find_program(QtCreatorExecutable
    NAMES
        qtcreator "Qt Creator"
    PATHS
        "${QtCreatorCorePath}/../../../bin"
        "${QtCreatorCorePath}/../../../MacOS"
    NO_DEFAULT_PATH
)
if(QtCreatorExecutable)
    add_custom_target(RunQtCreator
        COMMAND ${QtCreatorExecutable} -pluginpath $<TARGET_FILE_DIR:DeepSeekPlugin>
        DEPENDS DeepSeekPlugin
    )
    set_target_properties(RunQtCreator PROPERTIES FOLDER "qtc_runnable")
endif()

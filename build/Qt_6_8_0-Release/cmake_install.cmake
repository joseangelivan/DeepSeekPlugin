# Install script for directory: /home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/tmp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/bin/llvm-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseekplugin.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseekwidget.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseektool.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseekprojectgenerator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseekcodeeditor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseekpluginconstants.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseekplugintr.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/deepseeksettingsdialog.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qtcreator" TYPE FILE FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/messagehelper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins/libDeepSeekPlugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins/libDeepSeekPlugin.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins/libDeepSeekPlugin.so"
         RPATH "\$ORIGIN:\$ORIGIN/../:\$ORIGIN/../../Qt/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins" TYPE SHARED_LIBRARY OPTIONAL FILES "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/build/Qt_6_8_0-Release/lib/qtcreator/plugins/libDeepSeekPlugin.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins/libDeepSeekPlugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins/libDeepSeekPlugin.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins/libDeepSeekPlugin.so"
         OLD_RPATH "\$ORIGIN:\$ORIGIN/../:\$ORIGIN/../../Qt/lib:/opt/qtcreator-16.0.1/lib/qtcreator/plugins:/opt/qtcreator-16.0.1/lib/qtcreator:/opt/Qt/6.8.0/gcc_64/lib:"
         NEW_RPATH "\$ORIGIN:\$ORIGIN/../:\$ORIGIN/../../Qt/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/bin/llvm-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qtcreator/plugins/libDeepSeekPlugin.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ivan/Documentos/Ivan_&_Jacky/proyectos/DeepSeekPlugin/build/Qt_6_8_0-Release/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

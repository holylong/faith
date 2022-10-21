cmake_minimum_required(VERSION 3.5)

project(faith_ui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        settingsdialog.cpp
        settingsdialog.h
        settingsdialog.ui

        localrun.cpp
        localrun.h
        localrun.ui

        resources.qrc
)

add_library(faith_ui SHARED
    ${PROJECT_SOURCES}
)

set_target_properties(faith_ui PROPERTIES
    CXX_STANDARD  11
    DEFINE_SYMBOL QT_NO_SIGNALS_SLOTS_KEYWORDS
    DEFINE_SYMBOL FAITH_LIBRARY
    PUBLIC_HEADER "${OPEN_HEADERS}"
    VERSION       ${PROJECT_VERSION}
    SOVERSION     ${PROJECT_VERSION_MAJOR}
)

target_include_directories(faith_ui PRIVATE ${CMAKE_BINARY_DIR}/core)

target_link_libraries(faith_ui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(faith_ui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(faith_ui)
endif()

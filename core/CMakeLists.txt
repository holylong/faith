cmake_minimum_required(VERSION 3.5)

project(faith_core VERSION 0.1 LANGUAGES CXX)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ui)

file(RELATIVE_PATH RELATIVE_PLUGIN_PATH /${CMAKE_RUNTIME_OUTPUT_DIRECTORY} /${PLUGIN_OUTPUT_DIRECTORY})
configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/faith/config.h")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CORE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/launcher.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/launcher.h)

set(UI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.ui

    ${CMAKE_CURRENT_SOURCE_DIR}/ui/settingsdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/settingsdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/settingsdialog.ui

    ${CMAKE_CURRENT_SOURCE_DIR}/ui/localrun.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/localrun.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/localrun.ui

    ui/animationutil.h ui/animationutil.cpp

    ui/toptoolbar.h ui/toptoolbar.cpp
    ui/chatwidget.h ui/chatwidget.cpp
    ui/richedit.h ui/richedit.cpp
    ui/chatlayout.h ui/chatlayout.cpp
    ui/searchbar.h ui/searchbar.cpp
    ui/userlistwidget.h ui/userlistwidget.cpp
    ui/movingwidget.h ui/movingwidget.cpp
    ui/mainwidget.h ui/mainwidget.cpp

    idleservice.h idleservice.cpp

    ui/chatwidget.h ui/chatwidget.cpp
    ui/chatmessage.h ui/chatmessage.cpp
    ui/settingswidget.h ui/settingswidget.cpp
    ui/aboutwidget.h ui/aboutwidget.cpp
    ui/statisticwidget.h ui/statisticwidget.cpp
    ui/roomwidget.h ui/roomwidget.cpp
    ui/widgetutil.h ui/widgetutil.cpp

    config.h config.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ui/resources.qrc
)

add_library(faith_core SHARED ${CORE_SRCS} ${UI_SOURCES})

target_include_directories(faith_core PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/json/single_include)
target_link_libraries(faith_core PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Core)

# target_link_libraries(faith_core PRIVATE faith_ui)

set_target_properties(faith_core PROPERTIES
    CXX_STANDARD  11
    DEFINE_SYMBOL QT_NO_SIGNALS_SLOTS_KEYWORDS
    DEFINE_SYMBOL FAITH_LIBRARY
    PUBLIC_HEADER "${OPEN_HEADERS}"
    VERSION       ${PROJECT_VERSION}
    SOVERSION     ${PROJECT_VERSION_MAJOR}
)

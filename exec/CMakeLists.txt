cmake_minimum_required(VERSION 3.11)

add_executable(faith main.cc app.qrc)

target_link_libraries(faith PRIVATE faith_core Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(faith PRIVATE ${CMAKE_SOURCE_DIR}/core)
target_include_directories(faith PRIVATE ${CMAKE_BINARY_DIR}/core)

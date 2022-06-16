cmake_minimum_required(VERSION 3.22)
project(QtWork)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(src)

FILE(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*")
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        WebSockets
        Network
        REQUIRED)

add_executable(QtWork ${SRC_FILES})

target_link_libraries(QtWork
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebSockets
        Qt::Network)
cmake_minimum_required(VERSION 3.22)
project(QtWork)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


FILE(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*")
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
add_executable(QtWork src/main.cpp src/mainwindow.cpp src/main)
target_link_libraries(QtWork
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
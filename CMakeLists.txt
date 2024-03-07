cmake_minimum_required(VERSION 3.5)

project(IPMITool_GUI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(IPMITool_GUI
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
)

target_link_libraries(IPMITool_GUI PRIVATE Qt6::Widgets)

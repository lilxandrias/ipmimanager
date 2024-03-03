cmake_minimum_required(VERSION 3.15)
project(IPMITool_GUI)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Check if ipmitool is installed
find_program(IPMITOOL_EXECUTABLE ipmitool)

if(NOT IPMITOOL_EXECUTABLE)
    message(FATAL_ERROR "ipmitool is required to build this project.")
endif()

add_executable(IPMITool_GUI
    main.cpp
    MainWindow.cpp
    MainWindow.ui
)

target_link_libraries(IPMITool_GUI
    PRIVATE
    Qt6::Widgets
)

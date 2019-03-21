cmake_minimum_required(VERSION 3.5)
project(CUNYCal)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)


find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)



include_directories(.)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
set(CMAKE_INCLUDE_CURRENT_DIR ON)



set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(CUNYCal
        automode.cpp
        automode.h
        automode.ui
        Course.cpp
        Course.h
        CourseScanner.cpp
        CourseScanner.h
        main.cpp
        win1.cpp
        win1.h
        win1.ui
        res.qrc)


target_link_libraries(CUNYCal Qt5::Core)
target_link_libraries(CUNYCal Qt5::Widgets)
target_link_libraries(CUNYCal Qt5::Multimedia)
target_link_libraries(CUNYCal Qt5::MultimediaWidgets)
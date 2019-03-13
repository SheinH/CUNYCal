cmake_minimum_required(VERSION 3.13)
project(CUNYClasses)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "~/Qt/5.12.2/clang_64/lib/cmake")


find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)


include_directories(.)

add_executable(CUNYClasses
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ScheduleRegex.cpp ScheduleRegex.h)


target_link_libraries(CUNYClasses Qt5::Core)
target_link_libraries(CUNYClasses Qt5::Widgets)
target_link_libraries(CUNYClasses Qt5::Quick)

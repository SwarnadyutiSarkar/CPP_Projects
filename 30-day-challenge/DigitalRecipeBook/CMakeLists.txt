cmake_minimum_required(VERSION 3.5)
project(DigitalRecipeBook)

find_package(Qt5 REQUIRED COMPONENTS Widgets Sql)

set(CMAKE_CXX_STANDARD 11)

add_executable(DigitalRecipeBook main.cpp mainwindow.cpp mainwindow.ui recipeeditor.cpp recipeeditor.ui)

target_link_libraries(DigitalRecipeBook Qt5::Widgets Qt5::Sql)

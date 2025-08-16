cmake_minimum_required(VERSION 3.16)

project(SingletonValues VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)

add_subdirectory(main/)

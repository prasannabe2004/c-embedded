cmake_minimum_required(VERSION 3.22)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)

set(EXECUTABLE_NAME Executable)

add_executable(${EXECUTABLE_NAME} "main.c")


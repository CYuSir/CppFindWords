cmake_minimum_required(VERSION 3.12)

project(CppFileTools)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppFileTools main.cpp QueryResult.cpp TextQuery.cpp)

target_link_libraries(CppFileTools PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
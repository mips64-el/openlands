
cmake_minimum_required(VERSION 3.14)

project(openlands VERSION 0.0.1 LANGUAGES C)

add_subdirectory(src)

add_executable(openlands ${OPENLANDS_SOURCES})

target_link_libraries(openlands PUBLIC raylib)
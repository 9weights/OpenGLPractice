cmake_minimum_required(VERSION 3.10)
project(GLPractice)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(dependencies/glfw)

# Exe
add_executable(first first.cpp)
target_link_libraries(first PUBLIC glfw)
#target_include_directories(first PUBLIC . dependencies/)

cmake_minimum_required(VERSION 3.12)
project(GLPractice)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#cmake_policy(SET CMP0148 OLD)
set(CMAKE_POLICY_DEFAULT_CMP<0148> OLD)

# GLAD
add_subdirectory(dependencies/glad/cmake)
glad_add_library(glad STATIC API gl:core=4.6)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(dependencies/glfw)

# Exe
add_executable(first first.cpp)
target_link_libraries(first PUBLIC glad glfw)
target_include_directories(first PUBLIC . dependencies/)

cmake_minimum_required(VERSION 3.12)
project(GLPractice)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GLAD
add_subdirectory(dependencies/glad)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(dependencies/glfw)

# GLM
add_subdirectory(dependencies/glm)

# Exe
add_executable(first first.cpp)
target_link_libraries(first PUBLIC glad glfw)
target_include_directories(first PUBLIC . dependencies/)
add_executable(textureTest textureTry.cpp)
target_link_libraries(textureTest PUBLIC glad glfw glm)
target_include_directories(textureTest PUBLIC . dependencies/)

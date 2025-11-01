cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)

# Find GLFW
find_package(glfw3 REQUIRED)

add_executable(hello main.cpp)

# Link GLFW
target_link_libraries(hello glfw)

# Link OpenGL on Windows
if(WIN32)
    target_link_libraries(hello opengl32)
endif()
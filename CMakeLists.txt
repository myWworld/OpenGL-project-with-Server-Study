cmake_minimum_required(VERSION 3.10)
project(OpenGLGame)

set(CMAKE_CXX_STANDARD 17)

# GLFW
add_subdirectory(libs/glfw)

# GLAD
add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

# Executable
add_executable(OpenGLGame main.cpp)

# Include dirs
target_include_directories(OpenGLGame PRIVATE libs/glad/include libs/glfw/include)

# Linking
target_link_libraries(OpenGLGame PRIVATE glfw glad)

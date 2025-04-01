cmake_minimum_required(VERSION 3.10)
project(OpenGLGame)

set(CMAKE_CXX_STANDARD 17)

# Executable
add_executable(OpenGLGame main.cpp)
# GLFW
add_subdirectory(libs/glfw)

# GLAD
add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

#glm
target_include_directories(OpenGLGame PRIVATE include)

# Shader 서브디렉토리 추가
add_subdirectory(src/shader)


# Include dirs
target_include_directories(OpenGLGame PRIVATE libs/glad/include libs/glfw/include)

# Linking
target_link_libraries(OpenGLGame PRIVATE glfw glad opengl32 shader)
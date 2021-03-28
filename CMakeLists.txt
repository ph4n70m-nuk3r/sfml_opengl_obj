cmake_minimum_required(VERSION 3.10)

project("Foo Project" VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -O3")
# set(SFML_STATIC_LIBRARIES TRUE)

set(OpenGL_GL_PREFERENCE "GLVND")

add_executable(GameDev3 src/main.cpp)
target_include_directories(GameDev3 PUBLIC include)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(GLEW 2.1 REQUIRED)
find_package(OpenGL 1 REQUIRED)

target_link_libraries(GameDev3 GL GLEW sfml-graphics sfml-window sfml-system)

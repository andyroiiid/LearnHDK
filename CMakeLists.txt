cmake_minimum_required(VERSION 3.24)
project(LearnHDK)

list(APPEND CMAKE_PREFIX_PATH "$ENV{HFS}/toolkit/cmake")

set(CMAKE_CXX_STANDARD 17)

find_package(Houdini REQUIRED)

add_executable(LearnHDK main.cpp)

target_link_libraries(LearnHDK Houdini)

houdini_configure_target(LearnHDK)

cmake_minimum_required(VERSION 3.16)
project(GameEngine LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/SDL)
add_executable(GameEngine src/main.cc)

target_link_libraries(GameEngine PRIVATE SDL3::SDL3)
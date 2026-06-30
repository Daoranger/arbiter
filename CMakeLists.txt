cmake_minimum_required(VERSION 3.16)
project(ArbiterEngine LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/SDL)
add_executable(ArbiterEngine
        src/main.cc
        src/core/application.cc
        src/core/window.cc
)

if (WIN32)
    add_custom_command(TARGET ArbiterEngine POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:ArbiterEngine>
            $<TARGET_FILE_DIR:ArbiterEngine>
            COMMAND_EXPAND_LISTS
    )
endif()

target_link_libraries(ArbiterEngine PRIVATE SDL3::SDL3)
cmake_minimum_required(VERSION 4.2.2)
message(STATUS "------ COMPILING WITH CMAKE VERSION: ${CMAKE_VERSION} ------")

project (Arbiter
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)              # compiler to use C++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # make C++20 a strict requirement, older compiler that doesn't support C++20 will not build
set(CMAKE_CXX_EXTENSIONS OFF)           # use pure, standard C++20, disable compiler-specific extensions

include(FetchContent)

# SFML
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON                  # only fetch latest commit (not the whole repo history)
)
FetchContent_MakeAvailable(SFML)

# GoogleTest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.18.0
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(googletest)

add_executable(Arbiter
        demo/main.cpp
        src/Arbiter/Core/Application.cpp
        src/Arbiter/AI/Utility/Consideration.cpp
        src/Arbiter/AI/Utility/ResponseCurve.cpp
        src/Arbiter/AI/Utility/LinearCurve.cpp
        src/Arbiter/AI/Utility/Action.cpp
)

target_include_directories(Arbiter PRIVATE include)

target_link_libraries(Arbiter PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
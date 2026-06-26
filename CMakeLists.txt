cmake_minimum_required(VERSION 3.22)

project(OlympiadIDE VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -g)
endif()

add_executable(OlympiadIDE
    src/main.cpp
    src/runner/Runner.cpp
    src/connectors/PythonConnector.cpp
)


target_include_directories(OlympiadIDE PRIVATE include)
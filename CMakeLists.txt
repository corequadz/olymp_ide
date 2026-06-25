cmake_minimum_required(VERSION 3.15...4.1)


project(olymp_ide VERSION 0.0.1
    DESCRIPTION "IDE that includes specific CP tools"
    LANGUAGES CXX)


add_executable(olymp_ide src/main.cpp)


target_compile_features(olymp_ide PRIVATE cxx_std_20)


add_subdirectory(sandbox)


                  
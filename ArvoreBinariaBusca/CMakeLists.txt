cmake_minimum_required(VERSION 3.25)
project(ArvoreBinariaBusca)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ArvoreBinariaBusca
        ArvoreBinariaBusca.cpp
        ArvoreBinariaBusca.h
        main.cpp)

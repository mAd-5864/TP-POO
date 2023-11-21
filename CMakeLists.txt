cmake_minimum_required(VERSION 3.26)
project(TP_POO)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP_POO
        Main.cpp
        utils.h
        Classes/Regra.cpp
        Classes/Regra.h
        Classes/Processor.cpp
        Classes/Processor.h
)

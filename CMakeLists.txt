cmake_minimum_required(VERSION 3.21)
project(TP_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Classes)

add_executable(TP_POO
        Classes/Commands.cpp
        Classes/Commands.h
        Classes/Interface.cpp
        Classes/Interface.h
        Classes/Processador.cpp
        Classes/Processador.h
        Classes/Regra.cpp
        Classes/Regra.h
        Main.cpp
        utils.cpp
        utils.h
        Terminal.cpp
        Terminal.h
        curses.h
        Classes/Zonas.h
        Classes/Zonas.cpp
        Classes/Sensores.h
        Classes/Sensores.cpp
        Classes/Propriedades.h
        Classes/Propriedades.cpp
        Classes/Aparelhos.h
        Classes/Aparelhos.cpp)

target_link_libraries(${PROJECT_NAME} D:/Downloads/PDCurses-3.9/PDCurses-3.9/wincon/pdcurses.a)

cmake_minimum_required(VERSION 3.21)
project(TP_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Classes)

add_executable(TP_POO
        Classes/Aparelho.cpp
        Classes/Aparelho.h
        Classes/AparelhoAquecedor.cpp
        Classes/AparelhoAspersor.cpp
        Classes/AparelhoLampada.cpp
        Classes/AparelhoRefrigerador.cpp
        Classes/Habitacao.cpp
        Classes/Interface.cpp
        Classes/Processador.cpp
        Classes/Propriedade.cpp
        Classes/PropriedadeFumo.cpp
        Classes/PropriedadeLuz.cpp
        Classes/PropriedadeRadiacao.cpp
        Classes/PropriedadeSom.cpp
        Classes/PropriedadeTemperatura.cpp
        Classes/PropriedadeVibracao.cpp
        Classes/Regra.cpp
        Classes/RegraEntre.cpp
        Classes/RegraFora.cpp
        Classes/RegraIgualA.cpp
        Classes/RegraMaiorQue.cpp
        Classes/RegraMenorQue.cpp
        Classes/Sensor.cpp
        Classes/SensorFumo.cpp
        Classes/SensorHumidade.cpp
        Classes/SensorLuminosidade.cpp
        Classes/SensorMovimento.cpp
        Classes/SensorRadiacao.cpp
        Classes/SensorSom.cpp
        Classes/SensorTemperatura.cpp
        Classes/Zona.cpp
        Classes/PropriedadeHumidade.h
        Classes/PropriedadeHumidade.cpp
        Terminal.cpp
        Terminal.h
        utils.cpp
        utils.h
        curses.h
        Main.cpp
        Classes/Componente.cpp

)

target_link_libraries(${PROJECT_NAME} c:/PDCurses-3.9/wincon/pdcurses.a)

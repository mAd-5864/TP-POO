#include "PropriedadeTemperatura.h"

PropriedadeTemperatura::PropriedadeTemperatura() : valMin(-273){
    if (this->getValor()<valMin){
        this->setValor(valMin);
    }
}

string PropriedadeTemperatura::getNome() const{
    return "temperatura";

}

string PropriedadeTemperatura::getUnidade() const{
    return " graus";

}

PropriedadeTemperatura::~PropriedadeTemperatura(){}
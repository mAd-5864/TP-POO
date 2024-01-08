#include "PropriedadeHumidade.h"

PropriedadeHumidade::PropriedadeHumidade() : valMin(0), valMax(100){
    if (getValor() > 100){
        this->setValor(valMax);
    }
}

string PropriedadeHumidade::getNome() const{
    return "humidade";

}

string PropriedadeHumidade::getUnidade() const{
    return "%";

}

PropriedadeHumidade::~PropriedadeHumidade(){}
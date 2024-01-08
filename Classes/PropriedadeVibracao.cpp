#include "PropriedadeVibracao.h"

PropriedadeVibracao::PropriedadeVibracao() : valMin(0){
}

string PropriedadeVibracao::getNome() const{
    return "vibracao";

}

string PropriedadeVibracao::getUnidade() const{
    return "hz";

}

PropriedadeVibracao::~PropriedadeVibracao(){}
#include "PropriedadeRadiacao.h"


PropriedadeRadiacao::PropriedadeRadiacao() : valMin(0){
}

string PropriedadeRadiacao::getNome() const{
    return "radiacao";

}

string PropriedadeRadiacao::getUnidade() const{
    return " bec";

}

PropriedadeRadiacao::~PropriedadeRadiacao(){}
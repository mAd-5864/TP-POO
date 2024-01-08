#include "PropriedadeLuz.h"

PropriedadeLuz::PropriedadeLuz() : valMin(0){
}

string PropriedadeLuz::getNome() const{
    return "luz";

}

string PropriedadeLuz::getUnidade() const{
    return " lumens";

}

PropriedadeLuz::~PropriedadeLuz(){}
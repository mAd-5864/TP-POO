#include "Propriedade.h"

int Propriedade::cont = 0;

Propriedade::Propriedade() : valor(0) {}

Propriedade::~Propriedade() {

}

double Propriedade::getValor() const {
    return valor;
}


void Propriedade::setValor(double novoValor) {
    valor = novoValor;
}

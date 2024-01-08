#include "Aparelho.h"

Aparelho::Aparelho() {}

void Aparelho::setTipo(int tipo) {
    this->tipo = tipo;
}

char Aparelho::getTipo() {
    return tipo;
}

Aparelho::~Aparelho() {}

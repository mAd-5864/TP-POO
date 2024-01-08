#include "Sensor.h"

Sensor::Sensor(){}

void Sensor::setTipo(int tipo) {
    this->tipo = tipo;
}

char Sensor::getTipo() {
    return tipo;
}

Sensor::~Sensor() {}

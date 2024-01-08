#include "Componente.h"
#include <cstdlib>

Componente::Componente() {
    gerarID();
    desliga();
}

Componente::Componente(char representacao) : representacao(representacao) {
    gerarID();
}

void Componente::setRepresentacao(int novaRepresentacao) {
    representacao = novaRepresentacao;
}

char Componente::getRepresentacao() {
    return representacao;
}


int Componente::getID() {
    return id;
}

void Componente::setID(int novoID) {
    this->id = novoID;
}

void Componente::gerarID() {
    idHelp++;
    do {
        this->setID((1000 * idHelp) + std::rand() % 9000);
    } while (id >= 10000);
}

bool Componente::getEstado() {
    return estado;
}

int Componente::liga() {
    if (!getEstado()) {
        setEstado(true);
        return 1;
    }
    return 0;
}

int Componente::desliga() {
    if (getEstado()) {
        setEstado(false);
        return 1;
    }
    return 0;
}

void Componente::setEstado(bool novoEstado) {
    estado = novoEstado;
}

Componente::~Componente() {}

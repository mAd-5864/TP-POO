#ifndef TP_POO_COMPONENTE_H
#define TP_POO_COMPONENTE_H

#include "../utils.h"
#include <unordered_set>

class Componente {

public:
    int id;
    char representacao;
    bool estado;
    int idHelp = 0;

    // Constructors
    Componente();
    Componente(char representacao);

    // Member functions
    int liga();
    int desliga();
    void gerarID();
    void setID(int novoID);
    void setEstado(bool novoEstado);
    bool getEstado();
    void setRepresentacao(int novaRepresentacao);
    char getRepresentacao();
    int getID();

    // Destructor
    ~Componente();
};

#endif //TP_POO_COMPONENTE_H

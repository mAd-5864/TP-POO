// Propriedade.h
#ifndef TP_POO_PROPRIEDADE_H
#define TP_POO_PROPRIEDADE_H

#include "../utils.h"

using namespace std;

class Propriedade {
private:
    static int cont;
    double valor;

public:
    Propriedade();
    virtual ~Propriedade();
    virtual string getNome() const = 0;
    virtual string getUnidade() const = 0;
    double getValor() const;
    virtual void setValor(double novoValor);
};

#endif // TP_POO_PROPRIEDADE_H

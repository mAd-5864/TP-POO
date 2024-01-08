// PropriedadeFumo.h
#ifndef TP_POO_PROPRIEDADEFUMO_H
#define TP_POO_PROPRIEDADEFUMO_H

#include "Propriedade.h"

class PropriedadeFumo : public Propriedade {
private:
    double valMax, valMin;

public:
    PropriedadeFumo();
    string getNome() const override;
    string getUnidade() const override;
    ~PropriedadeFumo();
};

#endif // TP_POO_PROPRIEDADEFUMO_H

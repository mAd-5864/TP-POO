#ifndef TP_POO_PROPRIEDADELUZ_H
#define TP_POO_PROPRIEDADELUZ_H
#include "Propriedade.h"

class PropriedadeLuz : public Propriedade {
private:
    double valMin;

public:
    PropriedadeLuz();
    string getNome() const override;
    string getUnidade() const override;
    ~PropriedadeLuz();

};


#endif // TP_POO_PROPRIEDADELUZ_H

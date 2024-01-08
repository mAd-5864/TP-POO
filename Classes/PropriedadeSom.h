#ifndef TP_POO_PROPRIEDADESOM_H
#define TP_POO_PROPRIEDADESOM_H
#include "Propriedade.h"

class PropriedadeSom : public Propriedade{
private:
    double valMin;

public:
    PropriedadeSom();
    string getNome() const override;
    string getUnidade() const override;
    ~PropriedadeSom();

};


#endif //TP_POO_PROPRIEDADESOM_H

#ifndef TP_POO_PROPRIEDADETEMPERATURA_H
#define TP_POO_PROPRIEDADETEMPERATURA_H
#include "Propriedade.h"

class PropriedadeTemperatura : public Propriedade{
private:
    double valMin;

public:
    PropriedadeTemperatura();
    string getNome() const override;
    string getUnidade() const override;
    ~PropriedadeTemperatura();

};

#endif //TP_POO_PROPRIEDADETEMPERATURA_H

#ifndef TP_POO_PROPRIEDADEHUMIDADE_H
#define TP_POO_PROPRIEDADEHUMIDADE_H
#include "Propriedade.h"

class PropriedadeHumidade : public Propriedade {
private:
        double valMin, valMax;

public:
    PropriedadeHumidade();
    string getNome() const override;
    string getUnidade() const override;
    ~PropriedadeHumidade();

    };


#endif //TP_POO_PROPRIEDADEHUMIDADE_H

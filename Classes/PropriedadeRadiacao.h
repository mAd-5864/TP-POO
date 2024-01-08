#ifndef TP_POO_PROPRIEDADERADIACAO_H
#define TP_POO_PROPRIEDADERADIACAO_H
#include "Propriedade.h"

class PropriedadeRadiacao : public Propriedade{
private:
    double valMin;

public:
    PropriedadeRadiacao();
    string getNome() const override;
    string getUnidade() const override;
    ~PropriedadeRadiacao();

};


#endif //TP_POO_PROPRIEDADERADIACAO_H

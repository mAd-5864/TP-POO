#ifndef TP_POO_PROPRIEDADEVIBRACAO_H
#define TP_POO_PROPRIEDADEVIBRACAO_H
#include "Propriedade.h"

class PropriedadeVibracao : public Propriedade{
private:
    double valMin;

public:
    PropriedadeVibracao();
    string getNome() const override;
    string getUnidade() const override;
    ~PropriedadeVibracao();

};
#endif //TP_POO_PROPRIEDADEVIBRACAO_H

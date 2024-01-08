#ifndef TP_POO_APARELHOAQUECEDOR_H
#define TP_POO_APARELHOAQUECEDOR_H
#include "Aparelho.h"

class AparelhoAquecedor :public Aparelho{
public:
    AparelhoAquecedor(bool estado,char representacao);
    void liga();
    void desliga();

};

#endif //TP_POO_APARELHOAQUECEDOR_H

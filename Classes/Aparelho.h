#ifndef TP_POO_APARELHOS_H
#define TP_POO_APARELHOS_H
#include "../utils.h"
#include "Componente.h"

class Aparelho : public Componente{

private:
    char tipo;

public:
    Aparelho();
    char getTipo();
    void setTipo(int tipo);
    ~Aparelho();
};

#endif //TP_POO_APARELHOS_H

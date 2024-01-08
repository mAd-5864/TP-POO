#ifndef TP_POO_SENSORES_H
#define TP_POO_SENSORES_H

#include "../utils.h"
#include "Componente.h"


class Sensor : public Componente {
private:
    char tipo;

public:
    Sensor();
    void setTipo(int tipo);
    char getTipo();
    ~Sensor();
};


#endif //TP_POO_SENSORES_H

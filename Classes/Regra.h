// Regra.h

#ifndef TP_POO_REGRA_H
#define TP_POO_REGRA_H

#include "../utils.h"

// Enumeração definindo diferentes tipos de regras
enum class RuleType {
    EQUAL_TO,       // Igual a
    LESS_THAN,      // Menor que
    GREATER_THAN,   // Maior que
    BETWEEN,        // Entre
    OUTSIDE         // Fora do intervalo
};

// Classe representando uma regra
class Rule {
private:
    RuleType type;  // Tipo da regra
    double x;       // Valor de x na regra
    double y;       // Valor de y na regra

public:
    // Construtor
    Rule(RuleType type, double x, double y = 0.0);

    // Métodos de acesso (getters)
    RuleType getType() const;
    double getX() const;
    double getY() const;
};

#endif //TP_POO_REGRA_H

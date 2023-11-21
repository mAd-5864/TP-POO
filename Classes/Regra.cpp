// Regra.cpp

#include "Regra.h"

// Implementação dos métodos da classe Rule

// Construtor da classe Rule
Rule::Rule(RuleType type, double x, double y) : type(type), x(x), y(y) {}

// Método para obter o tipo da regra
RuleType Rule::getType() const { return type; }

// Método para obter o valor de x na regra
double Rule::getX() const { return x; }

// Método para obter o valor de y na regra
double Rule::getY() const { return y; }

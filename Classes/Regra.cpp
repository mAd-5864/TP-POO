#include "Regra.h"


Rule::Rule(RuleType type, double x, double y) : type(type), x(x), y(y) {}

RuleType Rule::getType() const { return type; }

double Rule::getX() const { return x; }

double Rule::getY() const { return y; }

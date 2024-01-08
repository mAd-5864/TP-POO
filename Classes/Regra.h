#ifndef TP_POO_REGRA_H
#define TP_POO_REGRA_H

#include "../utils.h"

enum class RuleType {
    EQUAL_TO,
    LESS_THAN,
    GREATER_THAN,
    BETWEEN,
    OUTSIDE
};

class Rule {
private:
    RuleType type;
    double x;
    double y;

public:

};

#endif //TP_POO_REGRA_H

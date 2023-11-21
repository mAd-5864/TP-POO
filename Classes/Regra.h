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
        Rule(RuleType type, double x, double y = 0.0);

        RuleType getType() const;
        double getX() const;
        double getY() const;
};


#endif //TP_POO_REGRA_H

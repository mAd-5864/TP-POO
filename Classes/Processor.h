#ifndef TP_POO_PROCESSOR_H
#define TP_POO_PROCESSOR_H
#include "Regra.h"


class Processor {
private:
    vector<Rule> rules;
    string command;

public:
    Processor(string  cmd);

    void addRule(const Rule& rule);

    void removeRule(int index);

    void updateCommand(const string& newCommand);

    bool evaluateRules(const vector<double>& sensorValues);
};


#endif //TP_POO_PROCESSOR_H

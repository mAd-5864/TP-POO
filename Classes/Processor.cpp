#include "Processor.h"

    Processor::Processor(string  cmd) : command(std::move(cmd)) {}

    void Processor::addRule(const Rule& rule) {
        rules.push_back(rule);
    }

    void Processor::removeRule(int index) {
        if (index >= 0 && index < rules.size()) {
            rules.erase(rules.begin() + index);
        }
    }

    void Processor::updateCommand(const string& newCommand) {
        command = newCommand;
    }

    bool Processor::evaluateRules(const vector<double>& sensorValues) {
        // Logic to evaluate rules using sensor values
        // This part needs implementation based on rule evaluation logic
        // For demonstration, let's return true always
        return true;
    }


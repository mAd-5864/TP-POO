#include "Processador.h"

Processador::Processador(string cmd) : command(std::move(cmd)) {}  // Inicializa o comando no construtor

void Processador::addRule(const Rule& rule) {
    rules.push_back(rule);  // Adiciona uma nova regra ao vetor de regras
}

void Processador::removeRule(int index) {
    if (index >= 0 && index < rules.size()) {
        rules.erase(rules.begin() + index);  // Remove a regra no índice especificado do vetor de regras
    }
}

void Processador::updateCommand(const string& newCommand) {
    command = newCommand;  // Atualiza o comando a ser processado
}

bool Processador::evaluateRules(const vector<double>& sensorValues) {
    // Lógica para avaliar as regras com base nos valores dos sensores
    // Esta parte precisa de implementação com base na lógica de avaliação de regras
    // Por enquanto, vamos sempre retornar verdadeiro para demonstração
    return true;
}
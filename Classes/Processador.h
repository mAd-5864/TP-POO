#ifndef TP_POO_PROCESSADOR_H
#define TP_POO_PROCESSADOR_H
#include "Regra.h"

class Processador {
private:
    vector<Rule> rules;   // Vetor para armazenar as regras a serem processadas
    string command;       // Comando a ser processado

public:
    Processador(string cmd); // Construtor que inicializa o objeto com um comando

    void addRule(const Rule& rule);  // Adiciona uma regra ao vetor de regras
    void removeRule(int index);      // Remove uma regra com base no índice no vetor de regras
    void updateCommand(const string& newCommand);  // Atualiza o comando a ser processado
    bool evaluateRules(const vector<double>& sensorValues);  // Avalia as regras com base nos valores dos sensores
};

#endif //TP_POO_PROCESSADOR_H


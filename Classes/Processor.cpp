#include "Processor.h"

Processor::Processor(string cmd) : command(std::move(cmd)) {}  // Inicializa o comando no construtor

void Processor::addRule(const Rule& rule) {
    rules.push_back(rule);  // Adiciona uma nova regra ao vetor de regras
}

void Processor::removeRule(int index) {
    if (index >= 0 && index < rules.size()) {
        rules.erase(rules.begin() + index);  // Remove a regra no índice especificado do vetor de regras
    }
}

void Processor::updateCommand(const string& newCommand) {
    command = newCommand;  // Atualiza o comando a ser processado
}

bool Processor::evaluateRules(const vector<double>& sensorValues) {
    // Lógica para avaliar as regras com base nos valores dos sensores
    // Esta parte precisa de implementação com base na lógica de avaliação de regras
    // Por enquanto, vamos sempre retornar verdadeiro para demonstração
    return true;
}


//Leitura do ficheiro de comandos

// Função para processar um comando
void processCommands(const std::string& comando) {
    // Implemente a lógica para processar cada tipo de comando
    // Por exemplo, você pode dividir a string do comando e agir com base nos valores
    // Aqui, estamos apenas imprimindo para ilustração
    std::cout << "A processar comando: " << comando << std::endl;
}

// Função para ler comandos de um arquivo
void readcomandsfile(const std::string& nomeArquivo) {
    // Abra o arquivo
    std::ifstream arquivo(nomeArquivo);

    // Verifique se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return;
    }

    // Processar cada linha do arquivo como um comando
    string linha;
    while (std::getline(arquivo, linha)) {
        // Chame a função para processar o comando
        processCommands(linha);
    }

    // Feche o arquivo após a leitura
    arquivo.close();
}
/*es
int main() { // main temporaria moço só para ver se dava
    // Nome do arquivo de comandos
    std::string nomeArquivo = "comandos.txt";

    readcomandsfile(nomeArquivo);

    return 0;
}
*/

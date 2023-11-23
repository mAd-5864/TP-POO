#include "Commands.h"

Commands::Commands() : nlines(), ncols(), n(), X(), Y(), idZona() {}

// Parse the command and extract components
bool Commands::parseCommand() {
    // Implement parsing logic here
    std::istringstream ss(commandString);
    std::string token;
    while (ss >> token) {
        arguments.push_back(token);
    }
    return true;
    //return validateCommand();
}

void Commands::ProxCommand() {
    cout << "[Prox] Comando ainda não implementado" << endl;
}

void Commands::AvancaCommand(int n) {
    cout << "[Avanca] Comando ainda não implementado" << endl;
}

void Commands::criarHab(int nLines, int nCols) {
    cout << "[criarHab] Comando ainda não implementado" << endl;
}

void Commands::removerHab() {
    cout << "[removerHab] Comando ainda não implementado" << endl;
}

void Commands::criarZona(int X, int Y) {
    cout << "[criarZona] Comando ainda não implementado" << endl;
}

void Commands::removerZona(int idZona) {
    cout << "[removerZona] Comando ainda não implementado" << endl;
}

void Commands::mostrarZonas() {
    cout << "[mostrarZona] Comando ainda não implementado" << endl;
}

void Commands::listarComponentesZona(int idZona) {
    cout << "[listarComponentesZona] Comando ainda não implementado" << endl;
}

void Commands::listarPropriedadesZona(int idZona) {
    cout << "[listarPropriedadesZona] Comando ainda não implementado" << endl;
}

#ifndef TP_POO_COMMANDS_H
#define TP_POO_COMMANDS_H

#include "../utils.h"

class Commands {
private:
    int nlines, ncols, n, X, Y, idZona;

public:
    Commands();
    void ProxCommand();
    void AvancaCommand(int n);
    void criarHab(int nLines, int nCols);
    void removerHab();
    void criarZona(int X, int Y);
    void removerZona(int idZona);
    void mostrarZonas();
    void listarComponentesZona(int idZona);
    void listarPropriedadesZona(int idZona);
};

#endif // TP_POO_COMMANDS_H

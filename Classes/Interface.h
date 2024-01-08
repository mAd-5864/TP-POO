#ifndef TP_POO_INTERFACE_H
#define TP_POO_INTERFACE_H
#include "../utils.h"
#include "Terminal.h"
#include "Habitacao.h"

using namespace term;

class Interface {
private:
        Window cmd;
        Window infos;
        Habitacao habitacao;

public:
    Interface();
    void leComando();
    string verificaComando(string userInput);
    void leComandoFich(const string& filename);
    virtual ~Interface();
};


#endif //TP_POO_INTERFACE_H

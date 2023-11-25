#ifndef TP_POO_INTERFACE_H
#define TP_POO_INTERFACE_H

#include "Terminal.h"
#include "../utils.h"

using namespace term;

class Interface {
private:
        Window cmd;
        Window infos;
        Window window;
        int sa;

public:
    Interface();
    void leComando();
    string verificaComando(string userInput);
    void leComandoFich(const string& filename);
    virtual ~Interface();
};


#endif //TP_POO_INTERFACE_H

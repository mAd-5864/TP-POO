#ifndef TP_POO_HABITACAO_H
#define TP_POO_HABITACAO_H
#include "../utils.h"
#include "Terminal.h"
#include "Zona.h"


using namespace term;

class Habitacao{
private:
    int flagApaga = 0;
    int tempo;
    map<int, Window> mapWin;
    Zona ** zonas;

public:
    Window instantes;
    int linhas, colunas;
    Habitacao();

    void atualiza();
    int hnova(int linhas, int colunas);
    int znova(int linha, int coluna);
    void avanca (int n);
    void prox ();
    string zlista(int id);
    int hrem();
    string zprops(int id);
    int cnovoP(int id, char componente, string comando);
    int crem(int id);
    void changeID(int linha, int coluna);
    int zrem(int id);
    int crem(int id, int idc);
    string zcomp(int id);
    int acom(int id, int idc, string comando);
    int pmod(int id, string nome, int valor);
    int cnovo(int id, char componente, char tipo);
    string passaInstante();

    void prox(int n);
};



#endif //TP_POO_HABITACAO_H

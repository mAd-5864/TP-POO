#ifndef TP_POO_ZONAS_H
#define TP_POO_ZONAS_H

#include <ostream>
#include "../utils.h"
#include "Aparelho.h"
#include "Sensor.h"
#include "Processador.h"
#include "Propriedade.h"
#include "PropriedadeFumo.h"
#include "PropriedadeHumidade.h"
#include "PropriedadeLuz.h"
#include "PropriedadeRadiacao.h"
#include "PropriedadeSom.h"
#include "PropriedadeTemperatura.h"
#include "PropriedadeVibracao.h"

class Zona {

private:
    int flagCriaP = 0;
    int flagTresA = 0;
    int flagTresR = 0;
    int flagOneA = 0;
    int flagOneS = 0;
    int flagOneR = 0;
    int flagSecS = 0;
    int flagCincoA = 0;
    int id;
    int linha, coluna;
    static int cont;
    vector<Aparelho*> aparelhos;
    vector<Sensor*> sensores;
    vector<Processador*> processadores;
    vector<Propriedade*> propriedades;



public:
    Zona();
    void aquecedor();
    void aspersor();
    void refrigerador();
    void setId(int id);
    void setLinha(int linha);
    void setColuna(int coluna);
    int adicionaAparelho(char tipo);
    int adicionaSensor(char tipo);
    int adicionaProcessador(const string& comando);
    string mostraPropriedades() const;
    void iniciaPropriedades();
    int apagarAparelho(int idc);
    int apagarSensor(int idc);
    int apagarProcessador(int idc);
    int mudaPopriedades(const string& nome ,int valor);
    int onOffAparelho(int idc, const string& comando);
    int getID() const;
    int getLinha() const;
    int getColuna() const;
    string mostraInfo() const;
    string mostraAparelhos() const;
    string mostraSensores() const;
    string mostraProcessadores() const;
    string checkAparelhos() ;
    void apagarZona();
    friend std::ostream &operator<<(std::ostream &os, const Zona &zona);
    ~Zona();
};

#endif //TP_POO_ZONA_H
#include "Interface.h"

Interface::Interface():
cmd(3, 26, 115, 3, true),
window(3, 3, 51, 22, true),
infos(56, 3, 61, 22, true) {}


    void Interface::leComando() {
        int nLines=0;
        string comando, userInput;

        do {
            cmd.clear();
            cmd << set_color(2) << ">>" << set_color(0);
            cmd >> userInput;
            if (nLines==20){
            infos.clear();
            nLines=0;
            }
            comando = verificaComando(userInput);
            nLines++;
        } while (comando != "sair");
    }


    string Interface::verificaComando(string userInput){

        int nArgumentos = 0, ticks, nLinhas, nColunas, coluna, linha, valorProp;
        string comando, idZona, idAparelho, idComp, idProc, idRegra, idSensor, letra, nome, tipcom, novoComando, novaRegra, comAparelho, filename;
        istringstream iss (userInput);
        iss >> comando;

        istringstream countiss (userInput);
        string arg;
        while(countiss>> arg){ nArgumentos++; }

        if (!userInput.empty()) {
            if (comando == "prox") {
                infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
            } else if (comando == "avanca") {
                iss >> ticks;
                if (nArgumentos !=2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: avanca <n>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "hnova") {
                iss >> nLinhas >> nColunas;
                if (nLinhas > 0 && nColunas > 0 && nArgumentos==3) {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                } else {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: hnova <num linhas> <num colunas>\n" << set_color(0);
                }
            } else if (comando == "hrem") {
                iss >> linha >> coluna;
                infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
            } else if (comando == "znova") {
                iss >> linha >> coluna;
                if (linha > 0 && coluna > 0 && nArgumentos==3) {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                } else {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: znova <linha> <coluna>\n" << set_color(0);
                }
            } else if (comando == "zrem") {
                iss >> idZona;
                if (idZona.empty() || nArgumentos!=2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: hnova <ID zona>\n" << set_color(0);

                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "zlista") {
                iss >> idZona;
                infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
            } else if (comando == "zcomp") {
                iss >> idZona;
                if (idZona.empty() || nArgumentos!=2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: zcomp <ID zona>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "zprops") {
                iss >> idZona;
                if (idZona.empty() || nArgumentos!=2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: zprops <ID zona>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "pmod") {
                iss >> idZona >> nome >> valorProp;
                if (idZona.empty() || nome.empty() || valorProp < 1 || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: pmod <ID zona> <nome> <valor>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "cnovo") {
                iss >> idZona >> letra >> tipcom;
                if (idZona.empty() ||  letra.empty() || tipcom.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: cnovo <ID zona> <s | p | a> <tipo | comando>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "crem") {
                iss >> idZona >> letra >> idComp;
                if (idZona.empty() || letra=="" || idComp.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: crem <ID zona> <s | p | a> <ID>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "rnova") {
                iss >> idZona >> idProc >> novaRegra >> idSensor;
                if (idZona.empty() || idProc.empty() || novaRegra.empty() || idSensor.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: rnova <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] [param2] [...]\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "pmuda") {
                iss >> idZona >> idProc >> novoComando;
                if (idZona.empty() || idProc.empty() || novoComando.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: pmuda <ID zona> <ID proc. regras> <novo comando>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "rlista") {
                iss >> idZona >> idProc;
                if (idZona.empty() || idProc.empty() || nArgumentos!=3) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: rlista <ID zona> <ID proc. regras>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "rrem") {
                iss >> idZona >> idProc >> idRegra;
                if (idZona.empty() || idProc.empty() || idRegra.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: rrem <ID zona> <ID proc. regras> <ID regra>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "asoc") {
                iss >> idZona >> idProc >> idAparelho;
                if (idZona.empty() || idProc.empty() || idAparelho.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: asoc <ID zona> <ID proc. regras> <ID aparelho>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "ades") {
                iss >> idZona >> idProc >> idAparelho;
                if (idZona.empty() || idProc.empty() || idAparelho.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: ades <ID zona> <ID proc. regras> <ID aparelho>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "acom") {
                iss >> idZona >> idProc >> comAparelho;
                if (idZona.empty() || idProc.empty() || comAparelho.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: acom <ID zona> <ID aparelho> <comando>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "psalva") {
                iss >> idZona >> idProc >> nome;
                if (idZona.empty() || idProc.empty() || nome.empty() || nArgumentos!=4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: psalva <ID zona> <ID proc. regras> <nome>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "prepoe") {
                iss >> nome;
                if (nome.empty() || nArgumentos!=2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: prepoe <nome>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "prem") {
                iss >> nome;
                if (nome.empty() || nArgumentos!=2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: prem <nome>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
                }
            } else if (comando == "plista") {
                infos << set_color(2) << "Comando [" << comando << "] ainda nao implementado\n" << set_color(0);
            } else if (comando == "exec") {
                iss >> filename;
                if (filename.empty()){
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: exec <nome de ficheiro>\n" << set_color(0);
                }else{
                    leComandoFich(filename);
                }
            } else {
                infos << set_color(4) << "O comando inserido nao existe\n" << set_color(0);
            }
        }
        return comando;
    }

void Interface::leComandoFich(const string& filename) {
    string linhas,comando;

    ifstream file;
    file.open(filename);

    if(!(file.is_open() && file.good())){
        infos << "Nao foi possivel abrir/ler o ficheiro" << "\n";
        return;
    }

    while (getline(file,linhas)){
        comando = verificaComando(linhas);

        if (comando == "sair"){
            return;
        }
    }
}


Interface::~Interface() {

}

#include "Interface.h"


Interface::Interface():
        cmd(3, 30, 80, 3, true),
        infos(85, 3, 70, 30, true),
        habitacao() {

}


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

    string Interface::verificaComando(string userInput) {

        int nArgumentos = 0, ticks, nLinhas, nColunas, coluna, linha, valorProp, idComp, idZona;
        string comando, cmd, idAparelho, idProc, idRegra, idSensor, nome, tipcom, novoComando, novaRegra, comAparelho, filename;
        char componente, tipo;
        istringstream iss(userInput);
        iss >> comando;

        istringstream countiss(userInput);
        string arg;
        while (countiss >> arg) { nArgumentos++; }

        if (!userInput.empty()) {

            if (comando == "prox") {
                infos << set_color(2) << "Avancou 1 instante\n" << set_color(0);
                habitacao.prox();

            } else if (comando == "avanca") {
                iss >> ticks;
                if (nArgumentos != 2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: avanca <n>\n" << set_color(0);

                } else {
                    infos << set_color(2) << "Avancou " << ticks << " instantes\n" << set_color(0);
                    habitacao.avanca(ticks);
                }


            } else if (comando == "hnova") {
                iss >> nLinhas >> nColunas;
                if (nLinhas > 1 && nLinhas < 5 && nColunas > 1 && nColunas < 5 && nArgumentos == 3) {
                    infos << set_color(2) << "Habitacao " << nLinhas << "x" << nColunas << " criada com sucesso\n"
                          << set_color(0);
                    habitacao.hnova(nLinhas, nColunas);

                } else if ((nLinhas > 4 && nColunas > 4 && nArgumentos == 3) ||
                           (nLinhas < 2 && nColunas < 2 && nArgumentos == 3)) {
                    infos << set_color(4) << "[ERRO] Tamanho invalido \n" << set_color(0);
                } else {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: hnova <num linhas> <num colunas>\n"
                          << set_color(0);
                }


            } else if (comando == "hrem") {
                habitacao.hrem();
                infos << set_color(2) << "Habitacao eliminada com sucesso\n" << set_color(0);


            } else if (comando == "znova") {
                iss >> linha >> coluna;
                if (linha > 0 && coluna > 0 && nArgumentos == 3) {
                    int resultado = habitacao.znova(linha, coluna);
                    if (resultado != 0) {
                        infos << set_color(2) << "Nova zona criada com sucesso\n" << set_color(0);
                        habitacao.atualiza();

                    } else {
                        infos << set_color(4) << "ERRO ao criar nova zona\n" << set_color(0);
                    }
                } else {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: znova <linha> <coluna>\n" << set_color(0);
                }


            } else if (comando == "zrem") {
                iss >> idZona;
                if (idZona < 0 || nArgumentos != 2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: hnova <ID zona>\n" << set_color(0);

                } else {
                    int resultado = habitacao.zrem(idZona);
                    if (resultado == 0) {
                        infos << set_color(4) << "Nao foi possivel encontrar zona[" << idZona << "]\n" << set_color(0);
                    } else {
                        infos << set_color(2) << "Zona " << idZona << " foi eleminada com sucesso\n" << set_color(0);
                    }
                }


            } else if (comando == "zlista") {
                iss >> idZona;
                if (idZona < 0 || nArgumentos != 2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: hnova <ID zona>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "Informacoes da zona[" << idZona << "]\n" << set_color(0);
                    string s = habitacao.zlista(idZona);
                    infos << s;
                }


            } else if (comando == "zcomp") {
                iss >> idZona;
                if (idZona < 0 || nArgumentos != 2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: zcomp <ID zona>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "A informacao esta disponivel dentro da zona\n" << set_color(0);
                    string s = habitacao.zcomp(idZona);
                    infos << s;
                }


            } else if (comando == "zprops") {
                iss >> idZona;
                if (idZona < 0 || nArgumentos != 2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: zprops <ID zona>\n" << set_color(0);
                } else {
                    infos << set_color(2) << "As propriedades da zona sao as seguintes:\n" << set_color(0);
                    string s = habitacao.zprops(idZona);
                    infos << s;
                }
            } else if (comando == "pmod") {
                iss >> idZona >> nome >> valorProp;
                if (idZona < 0 || nome.empty() || valorProp < 1 || nArgumentos != 4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: pmod <ID zona> <nome> <valor>\n" << set_color(0);
                } else {
                    int resultado = habitacao.pmod(idZona, nome, valorProp);
                    if (resultado == 0) {
                        infos << set_color(4) << "[ERRO] Impossivel modificar propriedade :/\n" << set_color(0);
                    } else {
                        infos << set_color(2) << "Propriedade modificada com sucesso" << set_color(0);
                    }
                }
            } else if (comando == "cnovo") {
                iss >> idZona >> componente;
                if (componente != 'p') {
                    iss >> tipo;
                    if (idZona < 0 || (componente != 'a' && componente != 's') || tipo == '\0') {
                        infos << set_color(4)
                              << "[ERRO] Sintaxe iii invalida: cnovo <ID zona> <s | p | a> <tipo | comando>\n"
                              << set_color(0);
                    } else {
                        int resultado = habitacao.cnovo(idZona, componente, tipo);
                        if (resultado == 0) {
                            infos << set_color(4) << "[ERRO] Impossivel adicionar componente :/\n" << set_color(0);
                        } else {
                            infos << set_color(2) << "Componente adicionado com sucesso" << set_color(0) << " id: "
                                  << resultado << "\n" << set_color(0);
                        }

                    }
                } else {
                    iss >> cmd;
                    if (idZona < 0 || componente != 'p' || cmd.empty()) {
                        infos << set_color(4) << "[ERRO] Sintaxe invalida: cnovo <ID zona> p <tipo | comando>\n"
                              << set_color(0);
                    } else {
                        int resultado = habitacao.cnovoP(idZona, componente, cmd);
                        if (resultado == 0) {
                            infos << set_color(4) << "[ERRO] Impossivel adicionar componente :/\n" << set_color(0);
                        } else {
                            infos << set_color(2) << "Componente adicionado com sucesso" << set_color(0) << " id: "
                                  << resultado << "\n" << set_color(0);
                        }
                    }
                }
            } else if (comando == "crem") {
                iss >> idZona >> componente >> idComp;
                if (idZona < 0 || (componente != 'a' && componente != 's' && componente != 'p') || idComp < 0 || nArgumentos != 4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: crem <ID zona> <s | p | a> <ID>\n"
                          << set_color(0);
                } else {
                    int resultado = habitacao.crem(idZona, idComp);
                    if (resultado == 0) {
                        infos << set_color(4) << "[ERRO] Impossivel eliminar componente :/\n" << set_color(0);
                    } else {
                        infos << set_color(2) << "Componente eleminado com sucesso\n" << set_color(0);
                    }
                }
            } else if (comando == "rnova") {
                iss >> idZona >> idProc >> novaRegra >> idSensor;
                if (idZona < 0 || idProc.empty() || novaRegra.empty() || idSensor.empty() || nArgumentos != 4) {
                    infos << set_color(4)
                          << "[ERRO] Sintaxe invalida: rnova <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] [param2] [...]\n"
                          << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "pmuda") {
                iss >> idZona >> idProc >> novoComando;
                if (idZona < 0 || idProc.empty() || novoComando.empty() || nArgumentos != 4) {
                    infos << set_color(4)
                          << "[ERRO] Sintaxe invalida: pmuda <ID zona> <ID proc. regras> <novo comando>\n"
                          << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "rlista") {
                iss >> idZona >> idProc;
                if (idZona < 0 || idProc.empty() || nArgumentos != 3) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: rlista <ID zona> <ID proc. regras>\n"
                          << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "rrem") {
                iss >> idZona >> idProc >> idRegra;
                if (idZona < 0 || idProc.empty() || idRegra.empty() || nArgumentos != 4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: rrem <ID zona> <ID proc. regras> <ID regra>\n"
                          << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "asoc") {
                iss >> idZona >> idProc >> idAparelho;
                if (idZona < 0 || idProc.empty() || idAparelho.empty() || nArgumentos != 4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: asoc <ID zona> <ID proc. regras> <ID aparelho>\n"
                          << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "ades") {
                iss >> idZona >> idProc >> idAparelho;
                if (idZona < 0 || idProc.empty() || idAparelho.empty() || nArgumentos != 4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: ades <ID zona> <ID proc. regras> <ID aparelho>\n"
                          << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }


            } else if (comando == "acom") {
                iss >> idZona >> idComp >> comAparelho;
                if (idZona < 0 || idComp < 0 || comAparelho.empty() || nArgumentos != 4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: acom <ID zona> <ID aparelho> <comando>\n"
                          << set_color(0);
                } else {
                    int resultado = habitacao.acom(idZona, idComp, comAparelho);
                    if (resultado == 1){
                        infos << set_color(2) << "Comando inserido com sucesso\n" << set_color(0);
                    } else {
                        infos << set_color(4) << "[ERRO] Nao foi possivel processar o comando :/\n" << set_color(0);
                    }
                }


            } else if (comando == "psalva") {
                iss >> idZona >> idProc >> nome;
                if (idZona < 0 || idProc.empty() || nome.empty() || nArgumentos != 4) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: psalva <ID zona> <ID proc. regras> <nome>\n"
                          << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "prepoe") {
                iss >> nome;
                if (nome.empty() || nArgumentos != 2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: prepoe <nome>\n" << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "prem") {
                iss >> nome;
                if (nome.empty() || nArgumentos != 2) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: prem <nome>\n" << set_color(0);
                } else {
                    infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
                }
            } else if (comando == "plista") {
                infos << set_color(4) << "Comando [" << comando << "] nao implementado\n" << set_color(0);
            } else if (comando == "exec") {
                iss >> filename;
                if (filename.empty()) {
                    infos << set_color(4) << "[ERRO] Sintaxe invalida: exec <nome de ficheiro>\n" << set_color(0);
                } else {
                    leComandoFich(filename);
                }

            } else if (comando == "sair") {
                abort();
            } else {
                infos << set_color(4) << "O comando inserido nao existe\n" << set_color(0);
            }
            return comando;
        }
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


Interface::~Interface() = default;

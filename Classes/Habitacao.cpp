#include "Habitacao.h"

Habitacao::Habitacao() : tempo(0), instantes(30, 1, 20, 3, true) {
    instantes << set_color(2) << "Instante: 0 " << "\n" << set_color(0);
}


void Habitacao::avanca (int n){
    this->tempo = this->tempo + n;
    instantes.clear();
    instantes << set_color(2) << "Instante: "<< tempo << "\n" << set_color(0);
    for (int i = 0; i < n; i++){
        passaInstante();
    }

}

void Habitacao::prox (){
    this->tempo ++;
    instantes.clear();
    instantes << set_color(2) << "Instante: " << tempo << "\n" << set_color(0);
    passaInstante();

}

string Habitacao::passaInstante() {
    ostringstream os;
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            os << "id: " << zonas[j][i].getID();
            os << zonas[j][i].checkAparelhos();
        }
    }
    return "A zona com o id introduzido nao foi encontrada";
}

int Habitacao::hnova(int linhas, int colunas) {

    mapWin.clear();

    if (this->flagApaga == 0) {
        Habitacao::hrem();
    }

    this->linhas = linhas;
    this->colunas = colunas;

    zonas = new Zona * [linhas];
    for (int i = 0; i < linhas; i++) {
        zonas[i] = new Zona[colunas];
        for (int j = 0; j < colunas ; j++) {
            // Chama o construtor para iniciar cada zona como vazia
            zonas[i][j] = Zona();
        }
    }


    int larguraTotal = 20 * linhas;
    int alturaTotal = 6 * colunas;
    int larguraZona = larguraTotal / colunas;
    int alturaZona = alturaTotal / linhas;
    int x = 3;
    int y = 4;
    int count = 0;

    for (int i = 1; i <= linhas * colunas; i++) {
        mapWin.emplace(i, Window(x, y, larguraZona, alturaZona));

        x += (larguraTotal / colunas);
        count++;

        if (count >= colunas) {
            y += alturaTotal / linhas;
            x = 3;
            count = 0;
        }
        auto it = mapWin.find(i);
        it->second << "[VAZIA]";
    }
    return 1;
}

int Habitacao::hrem() {
    // Limpa o mapa de janelas
    mapWin.clear();

    // Liberta a memória alocada para as zonas
    for (int i = 0; i < linhas; i++) {
        zonas[i]->apagarZona();
        delete[] zonas[i];
    }
    delete[] zonas;

    // Reinicia as variáveis para valores padrão
    linhas = 0;
    colunas = 0;


    this->flagApaga = 1;
    return 1;
}

string Habitacao::zlista(int id) {
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            if (zonas[j][i].getID() == id) {
                string s = zonas[j][i].mostraInfo();
                return s;
            }
        }
    }
    return "A zona com o id introduzido nao foi encontrada";
}


int Habitacao::znova(int linha, int coluna) {
    if (linha >= 0 && linha < linhas +1 && coluna >= 0 && coluna < colunas +1) {
        zonas[linha -1][coluna -1].iniciaPropriedades();
        zonas[linha -1][coluna -1].setColuna(coluna);
        zonas[linha -1][coluna -1].setLinha(linha);
        changeID(linha, coluna);
        return 1;
    } else {
        return 0;
    }
}

void Habitacao::changeID(int linha, int coluna) {
    int id = 0;
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            id++;
            if ((linha == j + 1) && (coluna == i + 1)) {
                zonas[j][i].setId(id);
            }
        }
    }
}

int Habitacao::zrem(int id) {
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            int index = j * colunas + i + 1;
            auto it = mapWin.find(index);

            if (it != mapWin.end()) {  // Verifica se o elemento foi encontrado no mapa
                if (zonas[j][i].getID() == id) {
                    it->second.clear();
                    it->second << "[VAZIA]";
                    zonas[j][i].apagarZona();
                    return 1;
                }
            }
            }
        }
    return 0;
}


int Habitacao::crem(int id, int idc) {
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            if (zonas[j][i].getID() == id) {
                zonas[j][i].apagarAparelho(idc);
                zonas[j][i].apagarSensor(idc);
                zonas[j][i].apagarProcessador(idc);
                return 1;
            }
        }
    }
    return 0;
}


string Habitacao::zcomp(int id) {
    string s;
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            if (zonas[i][j].getID() == id){
            s = zonas[j][i].mostraAparelhos();
            s += zonas[j][i].mostraSensores();
            s += zonas[j][i].mostraProcessadores();
            if (s.size() == 0){
                return "Sem componentes :(";
            }
            return s;
            }
        }
    }
    return "A zona com o id introduzido não foi encontrada";
}

string Habitacao::zprops(int id) {
    string s;
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            if (zonas[j][i].getID() == id) {
                s = zonas[j][i].mostraPropriedades();
                if (s.empty()) {
                    return "Sem Propriedades :(";
                }
                return s;
            }
        }
    }
    return "A zona com o id introduzido não foi encontrada";
}


int Habitacao::pmod(int id, string nome, int valor) {
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            if (zonas[j][i].getID() == id) {
                zonas[j][i].mudaPopriedades(nome, valor);
                return 1;
                }
            }
        }
    return 0;
}

int Habitacao::acom(int id, int idc, string comando) {
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            if (zonas[j][i].getID() == id) {
                zonas[j][i].onOffAparelho(idc, comando);
                return 1;
            }
        }
    }
    return 0;
}





int Habitacao::cnovo(int id, char componente, char tipo) {

    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            if (zonas[j][i].getID() == id) {
                if (componente == 'a') {
                    int resultado = zonas[j][i].adicionaAparelho(tipo);
                    return resultado;
                } else if (componente == 's'){
                    int resultado = zonas[j][i].adicionaSensor(tipo);
                    return resultado;
                }
            }
        }
    }
    return 0;
}

int Habitacao::cnovoP(int id, char componente, string comando) {

    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            if (zonas[j][i].getID() == id) {
                if (componente == 'p'){
                    int resultado = zonas[j][i].adicionaProcessador(comando);
                    return resultado;
                }
            }
    }}
    return 0;
}

void Habitacao::atualiza() {
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            int index = j * colunas + i + 1;  // Ajustado o cálculo do índice
            auto it = mapWin.find(index);

            if (it != mapWin.end()) {  // Verifica se o elemento foi encontrado no mapa

                if (zonas[j][i].getID() != 0) {
                    it->second.clear();
                    it->second << "ZONA " << zonas[j][i].getID();
                }
            }
        }
    }
}
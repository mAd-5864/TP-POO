#include "Zona.h"

int Zona::cont = 0;

Zona::Zona() : id(0), linha(0), coluna(0){}

void Zona::setId(int iid) {
    this->id = iid;
}

void Zona::setLinha(int lin) {
    this->linha = lin;
}

void Zona::setColuna(int col) {
    this->coluna = col;
}

int Zona::getID() const {
    return id;
}

string Zona::mostraInfo() const {
    ostringstream os;
    if (id == 0) {
        os << "[VAZIA] ";
    } else {
        os << "ID: " << id << "\nComponentes: " << (aparelhos.size() + processadores.size() + sensores.size());
    }
    os << "\n";
    return os.str();
}

string Zona::checkAparelhos() {
    ostringstream os;
    if (!aparelhos.empty()) {
        for (auto & aparelho : aparelhos) {
            if (aparelho->getEstado()) {
                if (aparelho->getTipo() == 'a') {
                    aquecedor();
                } else if (aparelho->getTipo() == 's') {
                    aspersor();
                } else if (aparelho->getTipo() == 'r') {
                    refrigerador();
                } else if (aparelho->getTipo() == 'l') {
                    for (auto & propriedade : propriedades) {
                        if (propriedade->getNome() == "luz")
                            propriedade->setValor(900);
                        }
                    }
                } else if (!aparelho->getEstado()){
                if (aparelho->getTipo() == 'a') {
                    if (flagOneA == 1){
                        flagOneA = 0;
                        for (auto & propriedade : propriedades) {
                            if (propriedade->getNome() == "som")
                                propriedade->setValor(propriedade->getValor() - 5);
                        }
                    }
                } else if (aparelho->getTipo() == 's') {
                    if (flagOneS == 1){
                        flagOneS = 0;
                        for (auto & propriedade : propriedades) {
                            if (propriedade->getNome() == "vibracao")
                                propriedade->setValor(propriedade->getValor() - 100);
                        }
                    }
                } else if (aparelho->getTipo() == 'r') {
                    if (flagOneR == 1){
                        flagOneR = 0;
                        for (auto & propriedade : propriedades) {
                            if (propriedade->getNome() == "som")
                                propriedade->setValor(propriedade->getValor() - 20);
                        }
                    }
                } else if (aparelho->getTipo() == 'l') {
                        for (auto & propriedade : propriedades) {
                            if (propriedade->getNome() == "luz")
                                propriedade->setValor(propriedade->getValor() - 900);
                        }
                    }
                }
            }
        }
    os << "\n";
    return os.str();
}

void Zona::aquecedor() {
    flagTresA++;

    if (flagOneA == 0) {
        flagOneA = 1;
        for (auto & propriedade : propriedades) {
            if (propriedade->getNome() == "som")
                propriedade->setValor(propriedade->getValor() + 5);
        }
    }

    if (flagTresA == 3) {
        for (auto & propriedade : propriedades) {
            if (propriedade->getNome() == "temperatura") {
                if (propriedade->getValor() < 50)
                    propriedade->setValor(propriedade->getValor() + 1);
            }
        }
        flagTresA = 0;
    }
}

void Zona::aspersor() {
    flagSecS++;
    if (flagOneS == 0) {
        flagOneS = 1;
        for (auto & propriedade : propriedades) {
            if (propriedade->getNome() == "humidade") {
                    propriedade->setValor(propriedade->getValor() + 50);
                    if(propriedade->getValor() > 75){
                        propriedade->setValor(75);
                }
            }
        }
        for (auto & propriedade : propriedades) {
            if (propriedade->getNome() == "vibracao") {
                propriedade->setValor(propriedade->getValor() + 100);
                }
            }
        }
        if (flagSecS == 2) {
        for (auto & propriedade : propriedades) {
            if (propriedade->getNome() == "fumo") {
                    propriedade->setValor(0);
                    flagSecS = 0;
            }
        }
    }
}

void Zona::refrigerador() {
    flagTresR++;

    if (flagOneR == 0) {
        flagOneR = 1;
        for (auto & propriedade : propriedades) {
            if (propriedade->getNome() == "som")
                propriedade->setValor(propriedade->getValor() + 20);
        }
    }

    if (flagTresR == 3) {
        for (auto & propriedade : propriedades) {
            if (propriedade->getNome() == "temperatura") {
                    propriedade->setValor(propriedade->getValor() - 1);
            }
        }
        flagTresR = 0;
    }
}

string Zona::mostraAparelhos() const {
    ostringstream os;
    if (aparelhos.empty()) {
        os << "Lista de Aparelhos: [VAZIA] ";
    } else {
        os << "ID: " << this->id << "\n";
        for (auto aparelho : aparelhos) {
            if (aparelho->getEstado()) {
                os << "| " << aparelho->getRepresentacao();
                os << "-> on |";
            }else if (!aparelho->getEstado()){
                os << "| " << aparelho->getRepresentacao();
                os << "-> off |";
            }
            }
        }
    os << " ";
    return os.str();
}


string Zona::mostraSensores() const {
    ostringstream os;
    if (sensores.empty()) {
        os << "Lista de Sensores: [VAZIA] ";
    } else {
        for (auto sensor : sensores) {
                os << "| " << sensor->getRepresentacao() << " |";
        }
    }
    os << " ";
    return os.str();
}


string Zona::mostraProcessadores() const {
    ostringstream os;
    if (processadores.empty()) {
        os << "Lista de Processadores: [VAZIA] ";
    } else {
        for (auto processadore : processadores) {
            if (processadore->getEstado()) {
                os << "| " << processadore->getRepresentacao();
                os << "-> on |";
            }else if (!processadore->getEstado()){
                os << "| " << processadore->getRepresentacao();
                os << "-> off |";
            }
        }
    }
    os << "\n";
    return os.str();
}

void Zona::iniciaPropriedades() {


    if (flagCriaP == 0) {

        flagCriaP = 1;

        auto *Fumo = new PropriedadeFumo;
        propriedades.push_back(Fumo);

        auto *Radiacao = new PropriedadeRadiacao;
        propriedades.push_back(Radiacao);

        auto *Humidade = new PropriedadeHumidade;
        propriedades.push_back(Humidade);

        auto *Temperatura = new PropriedadeTemperatura;
        propriedades.push_back(Temperatura);

        auto *Luz = new PropriedadeLuz;
        propriedades.push_back(Luz);

        auto *Som = new PropriedadeSom;
        propriedades.push_back(Som);

        auto *Vibracao = new PropriedadeVibracao;
        propriedades.push_back(Vibracao);

    }
}

int Zona::adicionaAparelho(char tipo) {

    auto* novoAparelho = new Aparelho;
    novoAparelho->setRepresentacao('a');

    if (tipo == 'a') {
        novoAparelho->setTipo('a');
    } else if (tipo == 's'){
        novoAparelho->setTipo('s');
    } else if (tipo == 'r'){
        novoAparelho->setTipo('r');
    } else if (tipo == 'l'){
        novoAparelho->setTipo('l');
    }
    int iid = novoAparelho->getID();
    aparelhos.push_back(novoAparelho);
    return iid;
}

int Zona::adicionaProcessador(const string& comando) {

    auto* novoProcessador = new Processador;
    novoProcessador->setRepresentacao('p');
    int iid = novoProcessador->getID();
    processadores.push_back(novoProcessador);
    if (comando== "liga"){
        novoProcessador->setEstado(true);
        return iid;
    } else if (comando== "desliga"){
        novoProcessador->setEstado(false);
        return iid;
    }

    return 0;
}

int Zona::adicionaSensor(char tipo) {

    auto* novoSensor = new Sensor;
    novoSensor->setRepresentacao('s');

    if (tipo == 't') {
        novoSensor->setTipo('t');
    } else if (tipo == 'v'){
        novoSensor->setTipo('v');
    } else if (tipo == 'm'){
        novoSensor->setTipo('m');
    } else if (tipo == 'd'){
        novoSensor->setTipo('d');
    } else if (tipo == 'h'){
        novoSensor->setTipo('h');
    } else if (tipo == 'o'){
        novoSensor->setTipo('o');
    } else if (tipo == 'f'){
        novoSensor->setTipo('f');
    }

    int iid = novoSensor->getID();
    sensores.push_back(novoSensor);
    return iid;
}

string Zona::mostraPropriedades() const {
    ostringstream os;
    for (auto propriedade : propriedades) {
        os << propriedade->getNome() << ":";
        os << propriedade->getValor() << " ";
        os << propriedade->getUnidade() << " | ";
    }
    os << "\n";
    return os.str();
}

int Zona::mudaPopriedades(const string& nome ,int valor) {

    for (auto propriedade : propriedades) {
        if (propriedade->getNome() == nome) {
            propriedade->setValor(valor);
            return 1;
        }
    }
    return 0;
}


void Zona::apagarZona() {
    for (Aparelho* aparelho : aparelhos) {
        delete aparelho;
    }
    aparelhos.clear();

    for (Sensor* sensor : sensores) {
        delete sensor;
    }
    sensores.clear();

    for (Processador* processador : processadores) {
        delete processador;
    }
    processadores.clear();

    for (Propriedade* propriedade : propriedades) {
        delete propriedade;
    }
    propriedades.clear();

    flagCriaP = 0;
    id = 0;
    linha = 0;
    coluna = 0;
    cont = 0;
}

int Zona::apagarAparelho(int idc) {
    for (auto it = aparelhos.begin(); it != aparelhos.end(); ++it) {
        if ((*it)->getID() == idc) {
            delete *it;
            aparelhos.erase(it);
            return 1;
        }
    }
    return 0;
}

int Zona::apagarSensor(int idc) {
    for (auto it = sensores.begin(); it != sensores.end(); ++it) {
        if ((*it)->getID() == idc) {
            delete *it;
            sensores.erase(it);
            return 1;
        }
    }
    return 0;
}

int Zona::apagarProcessador(int idc) {
    for (auto it = processadores.begin(); it != processadores.end(); ++it) {
        if ((*it)->getID() == idc) {
            delete *it;
            processadores.erase(it);
            return 1;
        }
    }
    return 0;
}

int Zona::onOffAparelho(int idc, const string& comando) {
    for (auto& aparelho : aparelhos) {
        if (aparelho->getRepresentacao() == 'a' && aparelho->getID() == idc) {
            if (comando == "liga") {
                aparelho->liga();
                return 1;
            } else if (comando == "desliga") {
                aparelho->desliga();
                return 1;
            }
        }
    }
    return 0;
}


int Zona::getLinha() const {
    return linha;
}

int Zona::getColuna() const {
    return coluna;
}

ostream &operator<<(ostream &os, const Zona &zona) {
    os << zona.mostraInfo();
    return os;
}

Zona::~Zona() {
    apagarZona();
}

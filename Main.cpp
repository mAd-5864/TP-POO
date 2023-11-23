#include "utils.h"
//#include "./Classes/Commands.h"

// Function to read and validate user commands
void getUserCommand() {
    string userInput;
    getline(cin, userInput);

    vector<string> arguments;
    stringstream ss(userInput);

        string arg;
    while (ss >> arg){
        arguments.push_back(arg);
    }
    if (!arguments.empty()) {
        string command = reinterpret_cast<basic_string<char> &&>(arg[0]);

        if (command == "prox") {
            //ProxCommand();
        } else if (command == "avanca") {
            if (arguments.size() > 1) {
                int n;
                istringstream(arguments[1]) >> n;
                //AvancaCommand(n);
            } else {
                cout << "[ERRO] Sintaxe invalida: avanca <n>" << endl;
            }
        } else if (command == "hnova") {
            if (arguments.size()==3){
                int nLines;
                int nCols;
                istringstream (arguments[1])>>nLines;
                istringstream (arguments[2])>>nCols;
                //criarHab(nLines, nCols);
            } else {
                cout << "[ERRO] Sintaxe invalida: hnova <num linhas> <num colunas>" << endl;
            }
        } else if (command == "hrem") {
            //removerHab();
        } else if (command == "znova") {
            if (arguments.size()==3){
                int X;
                int Y;
                istringstream (arguments[1])>>X;
                istringstream (arguments[2])>>Y;
                //criarZona(x, y);
            }else{
                cout << "[ERRO] Sintaxe invalida: znova <linha> <coluna>" << endl;
            }
        } else if (command == "zrem") {
            if (arguments.size()>1){
                int idZona;
                istringstream (arguments[1])>>idZona;
                //removerZona(idZona);
            }else{
                cout << "[ERRO] Sintaxe invalida: hnova <ID zona>" << endl;
            }
        } else if (command == "zlista") {
            //mostrarZonas();
        } else if (command == "zcomp") {
            if (arguments.size()>1){
                int idZona;
                istringstream (arguments[1])>>idZona;
                //listarComponentesZona(idZona);
            }else{
                cout << "[ERRO] Sintaxe invalida: zcomp <ID zona>" << endl;
            }
        } else if (command == "zprops") {
            if (arguments.size()>1){
                int idZona;
                istringstream (arguments[1])>>idZona;
                //listarPropriedadesZona(idZona);
            }else{
                cout << "[ERRO] Sintaxe invalida: zprops <ID zona>" << endl;
            }
        } else if (command == "pmod") {
            if (arguments.size()==4){
                int idZona;
                string nomeProp;
                int valorProp;
                istringstream (arguments[1])>>idZona;
                istringstream (arguments[2])>>nomeProp;
                istringstream (arguments[3])>>valorProp;
                //modificarValorProp(idZona, nomeProp, valorProp);
            }else{
                cout << "[ERRO] Sintaxe invalida: pmod <ID zona> <nome> <valor>" << endl;
            }
        } else if (command == "cnovo") {
            if (arguments.size()==4){
                int idZona;
                string novoComponente;
                int tipoComand;
                istringstream (arguments[1])>>idZona;
                istringstream (arguments[2])>>novoComponente;
                istringstream (arguments[3])>>tipoComand;
                //criarComponente(idZona, novoComponete, tipoComand);
            }else{
                cout << "[ERRO] Sintaxe invalida: cnovo <ID zona> <s | p | a> <tipo | comando>" << endl;
            }
        } else {
            cout << "[ERRO] Comando Invalido: " << command << endl;
        }
    }
}

int main() {
        getUserCommand();

    return 0;
}

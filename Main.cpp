#include "utils.h"

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
            if (arguments.size()!=3){
                int nLines;
                int nCols;
                istringstream (arguments[1])>>nLines;
                istringstream (arguments[2])>>nCols;
                //criarHab(nLines, nCols);
            }
        } else if (command == "hrem") {
            //removerHab();
        } else if (command == "znova") {
            if (arguments.size()!=3){
                int X;
                int Y;
                istringstream (arguments[1])>>X;
                istringstream (arguments[2])>>Y;
                //criarHab(nLines, nCols);
            }
        } else if (command == "zrem") {
            if (arguments.size()>1){
                int idZona;
                istringstream (arguments[1])>>idZona;
                //removerZona(idZona);
            }
        } else if (command == "zlista") {
            //mostrarZonas();
        } else if (command == "zcomp") {
            if (arguments.size()>1){
                int idZona;
                istringstream (arguments[1])>>idZona;
                //listarComponentes(idZona);
            }
        } else if (command == "zprops") {
            if (arguments.size()>1){
                int idZona;
                istringstream (arguments[1])>>idZona;
                //removerZona(idZona);
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

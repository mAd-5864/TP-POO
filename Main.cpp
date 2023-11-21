#include "utils.h"

// Function to read and validate user commands
void getUserCommand() {
    string userInput;
    cout << "Enter a command: ";
    getline(cin, userInput);

    vector<string> tokens = splitString(userInput, ' ');

    if (!tokens.empty()) {
        string command = tokens[0];

        if (command == "prox") {
            //handleProxCommand();
        } else if (command == "avanca") {
            if (tokens.size() > 1) {
                int n;
                istringstream(tokens[1]) >> n;
                //handleAvancaCommand(n);
            } else {
                cout << "Invalid syntax for avanca command. Usage: avanca <n>" << endl;
            }
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }
}

int main() {
        getUserCommand();

    return 0;
}

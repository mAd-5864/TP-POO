#include "utils.h"

// Function to read and validate user commands
void getUserCommand() {
    std::string userInput;
    std::cout << "Enter a command: ";
    std::getline(std::cin, userInput);

    std::vector<std::string> tokens = splitString(userInput, ' ');

    if (!tokens.empty()) {
        std::string command = tokens[0];

        if (command == "prox") {
            //handleProxCommand();
        } else if (command == "avanca") {
            if (tokens.size() > 1) {
                int n;
                std::istringstream(tokens[1]) >> n;
                //handleAvancaCommand(n);
            } else {
                std::cout << "Invalid syntax for avanca command. Usage: avanca <n>" << std::endl;
            }
        } else {
            std::cout << "Unknown command: " << command << std::endl;
        }
    }
}

int main() {
        getUserCommand();

    return 0;
}

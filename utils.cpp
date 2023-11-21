#include "utils.h"

vector<string> splitString(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

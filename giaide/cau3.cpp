#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool passwordTest(const string& s);

int main() {
    ifstream finput("PASSWORD.INP", ios::in);
    ofstream foutput("PASSWORD.OUT", ios::out | ios::trunc);
    if (!finput.is_open()) {
        cerr << "input error";
        return 1;
    } else if (!foutput.is_open()) {
        cerr << "output error";
        return 1;
    }
    string s;
    getline(finput, s);
    const size_t length = s.length();
    if (length <= 6) {
        foutput << "0\n";
        finput.close();
        foutput.close();
        return 0;
    }
    unsigned int passwords{};
    size_t L = length;
    while (L > 6) {
        for (size_t i = 0; i < length; i++) {
            string pass{};
            size_t endIndex = i + L;
            if (endIndex <= length) {
                pass = s.substr(i, L);
            }
            if (passwordTest(pass)) passwords++;
        }
        L--;
    }
    foutput << passwords << '\n';
    finput.close();
    foutput.close();
    return 0;
}

bool passwordTest(const string& s) {
    const size_t length = s.length();
    if (length <= 6) return false;
    bool consistLowerCase = false;
    bool consistUpperCase = false;
    bool consistDigit = false;
    for (const char c : s) {
        if (c >= 'a' && c <= 'z') consistLowerCase = true;
        else if (c >= 'A' && c <= 'Z') consistUpperCase = true;
        else if (isdigit(c)) consistDigit = true;
        if (consistLowerCase && consistUpperCase && consistDigit) break;
    }
    return consistLowerCase && consistUpperCase && consistDigit;
}

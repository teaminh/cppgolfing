#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    constexpr char INPUTFILE[] = "DIFFSSTR.INP";
    constexpr char OUTPUTFILE[] = "DIFFSSTR.OUT";
    string s;
    int n;
    ifstream input(INPUTFILE, ios::in);
    if (!input.is_open()) {
        cerr << "input error\n";
        return 1;
    }
    input >> n;
    input.ignore();
    getline(input, s);
    input.close();
    ofstream output(OUTPUTFILE, ios::out);
    if (!output.is_open()) {
        cerr << "output error\n";
        return 1;
    }
    if (s.empty()) {
        output << "0\n";
        output.close();
        return 0;
    }
    size_t l{ 0 };
    string o{};
    for (int i = 0; i < n; i++) {
        char chatAtI = s[i];
        if (o.find(chatAtI) != string::npos) {
            o = "";
            continue;
        } else o += chatAtI;
        if (l == 0) l = o.length();
        if (o.length() > l) l = o.length();
    }
    output << l << '\n';
    output.close();
    return 0;
}

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    constexpr char INPUTFILE[] = "NGOAC.INP";
    constexpr char OUTPUTFILE[] = "NGOAC.OUT";
    ifstream input(INPUTFILE, ios::in);
    if (!input.is_open()) {
        cout << "\n";
        return 1;
    }
    getline(input, s);
    input.close();
    ofstream output(OUTPUTFILE, ios::out | ios::trunc);
    if (!output.is_open()) {
        cout << "\n";
        return 1;
    }
    if (s.empty()) {
        output << "DUNG";
        output.close();
        return 0;
    }
    int demNgoacTrai { 0 };
    int ngoacTrai{}, ngoacPhai{};
    const size_t length = s.length();
    for (size_t i = 0; i < length; i++) {
        char charAtI = s[i];
        if (charAtI == '(') {
            demNgoacTrai++;
            ngoacTrai++;
        } else if (charAtI == ')') {
            ngoacPhai++;
            if (demNgoacTrai > 0) {
                demNgoacTrai--;
            }
        } else {
            output << "KHONG HOP LE";
            output.close();
            return 0;
        }
    }
    if (ngoacTrai != ngoacPhai) output << "KHONG DUNG";
    else output << (demNgoacTrai == 0 ? "DUNG" : "KHONG DUNG");
    output.close();
    return 0;
}

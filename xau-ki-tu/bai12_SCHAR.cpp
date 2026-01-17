#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream finput("BAI3.INP", ios::in);
    ofstream foutput("BAI3.OUT", ios::out | ios::trunc);
    
    if (!finput.is_open()) {
        cerr << "input error";
        return 1;
    } else if (!foutput.is_open()) {
        cerr << "output error";
        return 1;
    }

    int T;
    finput >> T;

    while (T--) {
        string s;
        finput >> s;

        int dem[26]{};

        for (int i = 0; i < s.length(); i++) {
            dem[s[i] - 'a']++;
        }

        int pos = -1;

        for (int i = 0; i < s.length(); i++) {
            if (dem[s[i] - 'a'] == 1) {
                pos = i + 1;
                break;
            }
        }

        foutput << pos << '\n';
    }

    finput.close();
    foutput.close();
    return 0;
}

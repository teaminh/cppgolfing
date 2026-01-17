#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream finput("KiTuChung.Inp");
    ofstream foutput("KiTuChung.Out");

    string X, Y;
    finput >> X;
    finput >> Y;

    for (char c = 'a'; c <= 'z'; c++) {
        bool coTrongX = false;
        bool coTrongY = false;

        for (int i = 0; i < X.length(); i++) {
            if (X[i] == c) {
                coTrongX = true;
                break;
            }
        }

        for (int i = 0; i < Y.length(); i++) {
            if (Y[i] == c) {
                coTrongY = true;
                break;
            }
        }

        if (coTrongX && coTrongY) {
            foutput << c << endl;
        }
    }

    finput.close();
    foutput.close();

    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream finput("BAI15.INP");
    ofstream foutput("BAI15.OUT");

    int n;
    string s;
    finput >> n;
    finput >> s;

    int x = 0, y = 0;
    int dir = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == 'L') {
            dir = dir - 1;
            if (dir < 0) dir = 3;
        }
        else if (c == 'R') {
            dir = dir + 1;
            dir %= 4;
        }
        else if (c == 'B') {
            dir = dir + 2;
            dir %= 4;
        }

        if (dir == 0) y++;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        else if (dir == 3) x--;
    }

    foutput << x << " " << y;

    finput.close();
    foutput.close();
    return 0;
}

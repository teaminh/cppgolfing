#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream finput("BAI14.INP");
    ofstream foutput("BAI14.OUT");

    int x, y;
    finput >> x >> y;

    int k;
    finput >> k;

    string s;
    finput >> s;

    int mx{}, my{};
    bool found = false;

    if (abs(mx - x) <= 1 && abs(my - y) <= 1) {
        foutput << 0 << '\n';
        found = true;
    }

    for (int i = 0; i < k; i++) {
        if (s[i] == 'R') mx++;
        if (s[i] == 'L') mx--;
        if (s[i] == 'U') my++;
        if (s[i] == 'D') my--;

        int t = i + 1;

        if (abs(mx - x) <= 1 && abs(my - y) <= 1) {
            foutput << t << '\n';
            found = true;
        }
    }

    if (!found) {
        foutput << -1;
    }

    finput.close();
    foutput.close();
    return 0;
}

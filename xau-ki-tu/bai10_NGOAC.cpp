#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    if (s.empty()) {
        cout << "DUNG\n";
        return 0;
    }
    int ngoacTrai { 0 };
    const size_t length = s.length();
    for (size_t i = 0; i < length; i++) {
        char charAtI = s[i];
        if (charAtI == '(') {
            ngoacTrai++;
        } else if (charAtI == ')') {
            if (ngoacTrai > 0) {
                ngoacTrai--;
            } else {
                cout << "KHONG DUNG";
                return 0;
            }
        } else {
            cout << "KHONG HOP LE";
            return 0;
        }
    }
    if (ngoacTrai == 0) cout << "DUNG";
    else cout << "KHONG DUNG";
    return 0;
}

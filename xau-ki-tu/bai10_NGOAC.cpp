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
    int demNgoacTrai{};
    unsigned int ngoacTrai{};
    unsigned int ngoacPhai{};
    const size_t length = s.length();
    for (size_t i = 0; i < length; i++) {
        char charAtI = s[i];
        if (charAtI == '(') {
            demNgoacTrai++;
            ngoacTrai++;
        } else if (charAtI == ')') {
            ngoacPhai++;
            if (ngoacTrai > 0) {
                demNgoacTrai--;
            }
        } else {
            cout << "KHONG HOP LE\n";
            return 0;
        }
    }
    if (ngoacTrai != ngoacPhai) cout << "KHONG DUNG\n";
    else cout << (demNgoacTrai == 0 ? "DUNG\n" : "KHONG DUNG\n");
    return 0;
}

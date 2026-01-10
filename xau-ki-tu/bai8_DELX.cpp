#include <iostream>
#include <string>

using namespace std;

int main() {
    char x;
    string s;
    cin >> x;
    cin.ignore();
    getline(cin, s);
    if (s.empty()) {
        cout << '\n';
        return 0;
    }
    const size_t length = s.length();
    string output{};
    for (size_t i = 0; i < length; i++) {
        char charAtI = s[i];
        if (charAtI != x) output += charAtI;
    }
    cout << output << '\n';
    return 0;
}

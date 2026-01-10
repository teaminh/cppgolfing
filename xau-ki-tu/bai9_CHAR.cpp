#include <iostream>
#include <string>

using namespace std;

char toLowerCase(char c) {
    return (c >= 'A' && c <= 'Z') ? (char)(c + 32) : c;
}

int main() {
    string s;
    getline(cin, s);
    if (s.empty()) {
        cout << '\n';
        return 0;
    }
    unsigned int a[26]{};
    const size_t length = s.length();
    int charCount { 0 };
    for (size_t i = 0; i < length; i++) {
        char c = toLowerCase(s[i]);
        if (c >= 'a' && c <= 'z') {
            a[c - 'a']++;
            charCount++;
        }
    }
    if (charCount == 0) {
        cout << '\n';
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        unsigned int aAtI = a[i];
        if (aAtI > 0) cout << (char)(i + 97) << ' ' << aAtI << '\n';
    };
    return 0;
}

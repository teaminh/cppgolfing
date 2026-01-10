#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    if (s.empty()) {
        cout << "0\n";
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
    cout << l << '\n';
    return 0;
}

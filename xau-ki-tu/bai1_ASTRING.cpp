#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  if (s.empty()) {
    cout << '\n';
    return 0;
  }
  for (size_t i = s.length(); i > 0; i--) {
    cout << s[i - 1];
  }
  cout << '\n';
  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  size_t length = s.length();
  while (length--) {
    cout << s[length];
  }
  cout << '\n';
  return 0;
}

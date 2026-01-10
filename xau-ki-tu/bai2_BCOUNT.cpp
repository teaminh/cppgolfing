#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  int a[10]{};
  const size_t length = s.length();
  for (size_t i = 0; i < length; i++) {
    char c = s[i];
    if (c >= '0' && c <= '9') a[c - '0']++;
  }
  for (int i = 0; i < 10; i++) cout << a[i] << (i == 9 ? '\n' : ' ');
  return 0;
}

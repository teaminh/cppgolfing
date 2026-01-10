#include <iostream>
#include <string>

using namespace std;

int main() {
  char x;
  string s;
  cin >> x;
  cin.ignore();
  getline(cin, s);
  const size_t length = s.length();
  int count { 0 };
  for (char c : s) {
    if (c == x) count++;
  }
  cout << count << '\n';
  for (int i = 0; i < length; i++) {
    if (s[i] == x) {
      cout << i;
      count--;
      if (count == 0) cout << '\n';
      else cout << ' ';
    }
  }
  return 0;
}

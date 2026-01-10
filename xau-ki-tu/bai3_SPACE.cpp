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
  int first = s.find(' ');
  int last = s.rfind(' ');
  if (first == string::npos || last == string::npos) {
    cout << '\n';
    return 0;
  }
  cout << first << ' ' << last << '\n';
  return 0;
}

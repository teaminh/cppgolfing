#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2, s;
  getline(cin, s1);
  getline(cin, s2);
  getline(cin, s);
  if (s1.empty()) {
    cout << s << '\n';
    return 0;
  }
  if (s.empty()) {
    cout << '\n';
    return 0;
  }
  const size_t lengthS1 = s1.length();
  const size_t length = s.length();
  string output{};
  for (size_t i = 0; i < length; i++) {
    char charAtI = s[i];
    if (charAtI == s1[0] && i + lengthS1 <= length) {
      string matched = s.substr(i, lengthS1);
      if (matched == s1) {
        output += s2;
        i += lengthS1 - 1;
      } else {
        output += charAtI;
      }
    } else {
      output += charAtI;
    }
  }
  cout << output << '\n';
  return 0;
}

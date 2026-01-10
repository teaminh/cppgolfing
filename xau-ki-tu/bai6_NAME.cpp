#include <iostream>
#include <string>

using namespace std;

char toUpperCase(char c) {
  return (c >= 'a' && c <= 'z') ? (char)(c - 32) : c;
}

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
  const size_t length = s.length();
  int words { 0 };
  bool inWord = false;
  string output{};
  for (size_t i = 0; i < length; i++) {
    char charAtI = s[i];
    if (charAtI != ' ') {
      if (!inWord) {
        inWord = true;
        if (words > 0) output += ' ';
        output += toUpperCase(charAtI);
        words++;
      } else output += toLowerCase(charAtI);
    } else inWord = false;
  }
  if (words == 0) {
    cout << '\n';
    return 0;
  }
  cout << output << '\n';
  return 0;
}

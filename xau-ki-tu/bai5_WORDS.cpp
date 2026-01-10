#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  if (s.empty()) {
    cout << "0\n";
    return 0;
  }
  const size_t length = s.length();
  int words = 0;
  bool inWord = false;
  string output{};
  for (size_t i = 0; i < length; i++) {
    char charAtI = s[i];
    if (charAtI != ' ') {
      if (!inWord) {
        inWord = true;
        output += charAtI;
        words++;
      } else {
        output += charAtI;
      }
    } else if (inWord) {
      inWord = false;
      output += '\n';
    }
  }
  if (words == 0) {
    cout << "0\n";
    return 0;
  }
  cout << words << '\n' << output;
  if (output.back() != '\n') cout << '\n';
  return 0;
}

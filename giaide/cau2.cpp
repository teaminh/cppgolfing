#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream finput("GROCERY.INP", ios::in);
    ofstream foutput("GROCERY.OUT", ios::out | ios::trunc);
    if (!finput.is_open()) {
        cerr << "input error";
        return 1;
    } else if (!foutput.is_open()) {
        cerr << "output error";
        return 1;
    }
    int n{}, k{};
    finput >> n;
    finput >> k;
    const int mSize = n * n;
    int items[mSize]{};
    for (int i = 0; i < mSize; i++) finput >> items[i];
    int totalValue{};
    for (int i = 0; i < mSize - 1; i++) {
        int itemAtI = items[i];
        for (int j = i + 1; j < mSize; j++) {
            int itemAtJ = items[j];
            int tempValue = itemAtI + itemAtJ;
            if (tempValue > totalValue && tempValue <= k) totalValue = tempValue;
            if (totalValue == k) break;
        }
        if (totalValue == k) break;
    }
    foutput << totalValue << '\n';
    finput.close();
    foutput.close();
    return 0;
}

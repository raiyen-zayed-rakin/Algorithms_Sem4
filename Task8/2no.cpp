#include <string>
#include <iostream>
using namespace std;

string intToBinary(int num, int length) {
    string binary = "";
    for (int i = length - 1; i >= 0; --i) {
        int bit = (num >> i) & 1;
        binary += to_string(bit);
    }
    return binary;
}

int main() {
    int freq[6];
    cout << "Enter frequencies for characters 'a' to 'f':\n";
    for (int i = 0; i < 6; ++i) {
        char ch = 'a' + i;
        cout << ch << ": ";
        cin >> freq[i];
    }

    int codeLength = 3;

    cout << "Fixed length codes:\n";
    for (int i = 0; i < 6; ++i) {
        char ch = 'a' + i;
        cout << ch << ": " << intToBinary(i, codeLength) << endl;
    }

    return 0;
}

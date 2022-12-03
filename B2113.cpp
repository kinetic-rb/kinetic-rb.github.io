#include <iostream>

using namespace std;

string s, k;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        (i + 1 == s.size()) ? k[i] = s[i] + s[0] : k[i] = s[i] + s[i + 1];
    }
    for (int i = 0; i < s.size(); i++)
        cout << k[i];
    return 0;
}
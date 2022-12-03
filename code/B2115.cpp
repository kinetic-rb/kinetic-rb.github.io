#include <bits/stdc++.h>

using namespace std;

char s[81];
int n;

int main() {
    cin.getline(s, 81);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        if ((s[i] >= 'b' && s[i] <= 'z') || (s[i] >= 'B' && s[i] <= 'Z')) {
            cout << --s[i];
            continue;
        }
        if (s[i] == 'a') {
            cout << 'z';
            continue;
        }
        if (s[i] == 'A' || s[i] == '@') {
            cout << 'Z';
            continue;
        }
        cout << s[i];
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long a, b[25][25];

int main() {
    cin >> a;
    b[0][0] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j < i; j++) {
            b[i][j] += b[i - 1][j - 1] + b[i - 1][j];
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}
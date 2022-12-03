#include <iostream>
#include <map>

using namespace std;

int f[1010] = { 1 }, s[1010] = { 1 };

inline void set(int n) {
    f[n] = s[n / 2];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = s[i >> 1];
        s[i] = s[i - 1] + f[i];
    }
    cout << f[n];
    return 0;
}
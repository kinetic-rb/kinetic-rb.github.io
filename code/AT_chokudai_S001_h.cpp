#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int read() {
    int f = 1, d = 0;
    char t = getchar();
    while (t < '0' || t > '9') {
        if (t == '-')f = -1;
        t = getchar();
    }
    while (t >= '0' && t <= '9') {
        d = d * 10 + t - '0';
        t = getchar();
    }
    return f * d;
}

int a[100010], s[100010];
int n, tmp, tot;

int main() {
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    s[++tot] = a[1];
    for (auto i = 2; i <= n; i++) {
        if (a[i] > s[tot]) {
            s[++tot] = a[i];
        } else {
            *lower_bound(s + 1, s + tot + 1, a[i]) = a[i];
        }
    }
    cout << tot;
    return 0;
}
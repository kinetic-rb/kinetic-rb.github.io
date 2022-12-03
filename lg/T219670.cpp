#include <bits/stdc++.h>

using namespace std;

char n[30], t[30], l1, l2, len;

int main() {
    int a, b;
    cin >> n >> a >> b;
    len = strlen(n);
    for (int i = 1; i <= len; i++)
        t[i] = n[strlen(n) - i];
    l1 = t[++a];
    l2 = t[++b];
    t[b] = l1;
    t[a] = l2;
    for (int i = 1; i <= len; i++)
        n[i] = t[len - i];
    cout << n;
    return 0;
}
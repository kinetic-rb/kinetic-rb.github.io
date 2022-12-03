#include <bits/stdc++.h>

using namespace std;

inline int cti(char x) {
    if(x >= '0' && x <= '9')
        return x - '0';
    return x - 'A' + 10;
}

char n[8], an[8];

int main() {
    ios_base::sync_with_stdio(false);
    register int a, len, s10 = 0;
    cin >> len >> a >> n;
    for (register int i = 1; i <= len; i++)
        an[i] = n[len - i];
    for (register int i = 1; i <= len; i++)
        s10 += cti(an[i]) * int(pow(a, i - 1));
    cout << s10;
    return 0;
}
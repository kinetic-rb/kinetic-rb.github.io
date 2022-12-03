#include <bits/stdc++.h>

using namespace std;

int main() {
    char s[256];
    int ans = 0, i;
    gets(s);
    for (i = 0; i <= strlen(s); i++)
        if (s[i] >= '0' && s[i] <= '9')
            ans++;
    cout << ans;
    return 0;
}
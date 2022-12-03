#include <iostream>

using namespace std;

int num[2002], f[2002], path[2002];

int main() {
    int n, ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    ans = n;
    for (int i = n; i > 0; i--) {
        f[i] = 1;
        for (int j = i + 1; j <= n; j++)
            if (num[j] > num[i] and f[j] >= f[i])
                f[i] = f[path[i] = j] + 1;
        if (f[i] >= f[ans])
            ans = i;
    }
    for (cout << f[ans] << '\n'; ans; ans = path[ans])
        cout << ans << ' ';
    return 0;
}
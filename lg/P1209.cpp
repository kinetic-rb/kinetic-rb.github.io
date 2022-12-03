#include <iostream>
#include <algorithm>

using namespace std;

int num[205], cf[205];

int main() {
    int m, s, c, ans;
    cin >> m >> s >> c;
    if (m > c) {
        cout << c;
        return 0;
    }
    for (int i = 0; i < c; i++)
        cin >> num[i];
    sort(num, num + c);
    ans = num[c - 1] - num[0] + 1;
    for (int i = 1; i < c; i++) {
        cf[i - 1] = num[i] - num[i - 1];
    }
    sort(cf, cf + c - 1);
    reverse(cf, cf + c - 1);
    for (int i = 0; i < m - 1; i++)
        ans -= cf[i] - 1;
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

register_t n, num[1001];
map <int, bool> re;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 2; i <= n; i++)
        re[int(abs(num[i] - num[i - 1]))] = true;
    for (int i = 1; i < n; i++)
        if (!re[i]) {
            cout << "Not jolly";
            return 0;
        }
    cout << "Jolly";
    return 0;
}
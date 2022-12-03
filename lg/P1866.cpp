#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    register int n, *num = new int [60];
    register long ans = 1;
    cin >> n;
    for (register int i = 0; i < n; i++)
        cin >> num[i];
    stable_sort(num, num + n);
    for (register int i = 0; i < n; i++) {
        ans *= (num[i] - i);
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}
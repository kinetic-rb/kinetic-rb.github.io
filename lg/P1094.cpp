#include <iostream>
#include <algorithm>

using namespace std;

int p[30005];

int main() {
    int w, n, ans = 0;
    cin >> w >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    stable_sort(p + 1, p + n + 1);
    for (int i = n, k = 1; i >= k; --i) {
        if (i != k && p[i] + p[k] <= w) {
            ++k;
        }
        ++ans;
    }
    cout << ans;
    return 0;
}
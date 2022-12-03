#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int ac[55] = { 0 };
    ios_base::sync_with_stdio(false);
    int n, h;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ac[i];
    }
    stable_sort(ac + 1, ac + n + 1);
    cin >> h;
    if (h < ac[1]) {
        cout << "1
";
        return 0;
    }
    if (h > ac[n]) {
        cout << ++n << '\n';
        return 0;
    }
    for (int i = 1; i < n; i++)
        if (ac[i] < h && ac[i + 1] > h) {
            cout << ++i << '\n';
            return 0;
        }
    return 0;
}
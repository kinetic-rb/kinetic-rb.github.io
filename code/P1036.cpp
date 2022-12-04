#include <iostream>

using namespace std;

int num[25];
int n, k, cnt;

inline bool IP(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (!(x % i))
            return false;
    return true;
}

inline void so(int x, int sum, int pos) {
    if (x > n)
        return;
    if (pos == k) {
        if (IP(sum))
            cnt++;
        return;
    }
    so(x + 1, sum, pos);
    so(x + 1, sum + num[x], pos + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    so(0, 0, 0);
    cout << cnt;
    return 0;
}
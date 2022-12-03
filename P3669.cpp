#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;

struct AC {
    int sum, num;
    inline bool operator < (const AC & x) const {
        return x.num < num;
    }
} cow[100010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cow[i].sum >> cow[i].num;
    sort(cow, cow + n);
    for (int i = 0, j = n - 1; i <= j;) {
        int x = min(cow[i].sum, cow[j].sum);
        ans = max(ans, cow[i].num + cow[j].num);
        cow[i].sum -= x;
        cow[j].sum -= x;
        i += cow[i].sum < 1;
        j -= cow[j].sum < 1;
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
    int Val, presum;
} ac[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> ac[i].Val;
        ac[i].presum = (ac[i - 1].presum + ac[i].Val) % 1000000007;
    }
    for(int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        cout << (ac[r].presum - ac[l - 1].presum + 1000000007) % 1000000007 << '\n';
    }
    return 0;
}
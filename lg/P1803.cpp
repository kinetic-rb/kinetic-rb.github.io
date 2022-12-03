#include <iostream>
#include <algorithm>

using namespace std;

struct Match {
    int start, end;
} M[1000005];

int main() {
    int n, pos = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> M[i].start >> M[i].end;
    stable_sort(M, M + n, [](const Match &x, const Match &y) {
        return x.end < y.end;
    });
    for (int i = 0; i < n; i++) {
        if (pos <= M[i].start) {
            pos = M[i].end;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <iomanip>

using namespace std;

int cnt[4];

int main() {
    int n;
    double e;
    cin >> n;
    for (e = 100.0 / n; n--;) {
        int c;
        cin >> c;
        if (c < 19)
            cnt[0]++;
        else if (c < 36)
            cnt[1]++;
        else if (c < 61)
            cnt[2]++;
        else
            cnt[3]++;
    }
    cout << fixed << setprecision(2) << cnt[0] * e << "%
" << cnt[1] * e << "%
" << cnt[2] * e << "%
" << cnt[3] * e << '%';
    return 0;
}
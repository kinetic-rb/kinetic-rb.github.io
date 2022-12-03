#include <iostream>
#include <algorithm>

using namespace std;

int f[101][101], d, g, ans;
struct laji{
    int T,F,H;
}a[101];

bool cmp(laji i,laji j) {
    return i.T < j.T;
}

int main() {
    cin >> d >> g;
    for(int i = 1; i <= g; i++)
        cin >> a[i].T >> a[i].F >> a[i].H;
    sort(a + 1, a + 1 + g, cmp);
    f[0][0] = 10;
    for(int i = 1; i <= g; i++) {
        for(int j = 0; j < d; j++) {
            if(a[i].T <= f[i - 1][j]) f[i][j] = f[i - 1][j] + a[i].F;
        }
        for(int j = 0; j < d; j++) {
            if(a[i].T <= f[i - 1][j])
                if(j + a[i].H >= d) {
                    cout << a[i].T;
                    return 0;
                }
            f[i][j + a[i].H] = max(f[i][j + a[i].H], f[i - 1][j]);
        }
    }
    for(int i = 1; i <= g; i++) {
        for(int j = 0; j < d; j++)
            ans = max(ans, f[i][j]);
    }
    cout << ans;
    return 0;
}
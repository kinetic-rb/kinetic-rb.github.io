#include<bits/stdc++.h>

using namespace std;

int n, m;

double f[100010], a[100010], all[100010];

inline bool check(double mid){
    int i;
    double minn = 999999, ans = -1;
    all[0] = 0;
    for(i = 1; i <= n; i++) {
        a[i] = f[i] - mid;
        all[i] = all[i - 1] + a[i];
    }
    for(i = m; i <= n; i++){
        minn = min(minn, all[i-m]);
        ans = max(ans, all[i] - minn);
    }
    return ans >= 0;
}
int main( ){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int i, j;
    double l = 0, r = 3000, emp = 1e-6, mid;
    for(i = 1; i <= n; i++)
        cin >> f[i];
    while(r - l > emp) {
        mid = ( l + r ) / 2;
        check(mid)? l = mid : r = mid;
    }
    cout << int( r * 1000);
}
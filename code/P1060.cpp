#include <iostream>

using namespace std;

int sum = 0, ans = 0, n, m;
int v[30005], w[30005];

inline void so(int _x, int _v, int _w) {
    if(_x == m) {
        if(_w <= n)
            ans = max(int(ans), _v);
        return;
    }
    so(_x + 1, _v, _w);
    so(_x + 1, _v + v[_x], _w + w[_x]);
}

int main() {
    ios_base ::sync_with_stdio(false); 
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> w[i] >> v[i];
        v[i] *= w[i];
    }
    so(0, 0, 0);
    cout << ans;
    return 0;
}
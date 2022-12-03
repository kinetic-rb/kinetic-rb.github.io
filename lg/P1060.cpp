#include "iostream"
#define MAXV 30005

using namespace std;

long long sum = 0, ans = 0;
int n, m;
int v[MAXV], w[MAXV];
//\u5f53\u524d\u8003\u8651\u7b2cx\u4e2a\u6570\u662f\u5426\u5728\u5b50\u96c6\u4e2d\uff08\u662f\u5426\u9009\u62e9\u7b2cx\u4e2a\u6570\uff09
void so(int _x, int _v, int _w) { //\u4ef7\u503c\uff0c\u94b1
    if(_x == m) {
        if(_w <= n) {
            ans = max(int(ans), _v);
        }
        return;
    }
    so(_x + 1, _v, _w);
    so(_x + 1, _v + v[_x], _w + w[_x]);
}

int main()
{
    ios_base ::sync_with_stdio(false); //\u663e\u6446
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> w[i] >> v[i];
        v[i] *= w[i];
    }
    so(0, 0, 0);
    cout << ans;
    return 0;
}
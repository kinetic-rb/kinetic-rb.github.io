#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int ac[101], MAX;

bitset <25000> mon;

bool vis[25010];

void dfs(int x, int cnt, int last, int a) {
    for(auto i = last; i <= a; i++) {
        if(x + ac[i] <= ac[a] && !vis[x + ac[i]]) {
            MAX = max(MAX, x + ac[i]);
            vis[x + ac[i]] = true;
            mon[x + ac[i]] = cnt;
            dfs(x + ac[i], cnt + 1, i, a);
        }
    }
}

void set(int & a) {
    for(auto i = 0; i <= MAX; i++) {
        vis[i] = false;
    }
    MAX = 0;
    scanf("%d", &a);
    for(auto i = 1; i <= a; ++i)
        scanf("%d", &ac[i]);
    sort(ac + 1, ac + a + 1);
    dfs(0, 0, 1, a);
}

int main() {
    auto t = 0;
    for(scanf("%d", &t); t; t--) {
        auto a = 0;
        set(a);
        auto m = a;
        for(auto i = 1; i <= a; i++)
            if(mon[ac[i]])
                m--;
        cout << m << endl;
    }
    return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17

*/
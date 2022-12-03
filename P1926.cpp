#include <iostream>

using namespace std;

int num[1000][2];
int n, m, k, r, MAX;

inline void dfs(int idx, int time, int mark, int donum) {
    if (idx == n + m + 1) {
        if (time > -1 && mark >= k)
            MAX = max(MAX, donum); 
        return;
    }
    if (num[idx][0] <= time) {
        if (idx <= n)
            dfs(idx + 1, time - num[idx][0], mark, donum + 1);
        else
            dfs(idx + 1, time - num[idx][0], mark + num[idx][1], donum);
    }
    dfs(idx + 1, time, mark, donum);
}

int main() {
  cin >> n >> m >> k >> r;
    for(int x = 1; x <= n + m; ++x)
        cin >> num[x][0];
    for(int x = n + 1; x <= n + m; ++x)
        cin >> num[x][1];
    dfs(1, r, 0, 0);
    cout << MAX;
    return 0;
}
#include <iostream>

using namespace std;

int num[35];
int n, v, MIN = 0x7fffffff;

inline void dfs(int idx, int sum) {
    if (sum > v)
        return;
    if (idx == n) {
        MIN = min(MIN, v - sum);
        return;
    }
    dfs(idx + 1, sum);
    dfs(idx + 1, sum + num[idx]);
}

int main() {
    cin >> v >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    dfs(0, 0);
    cout << MIN;
    return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

int s[5], a[25];
int left, right, minn;

void dfs(int p, int i) {
    if (p > i) {
        minn = min(minn, max(left, right));
        return;
    }
    left += a[p];
    dfs(p + 1, i);
    left -= a[p];
    right += a[p];
    dfs(p + 1, i);
    right -= a[p];
}

int main() {
    scanf("%d%d%d%d", &s[1], &s[2], &s[3], &s[4]);
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= s[i]; j++) {
            scanf("%d", &a[j]);
        }
        left = 0, right = 0;
        minn = 0x7fffffff;
        dfs(1, s[i]);
        ans += minn;
    }
    printf("%d", ans);
    return 0;
}
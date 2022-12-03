#include<cstdio>
#include<algorithm>

using namespace std;

int a[1010];
bool cmp(int x, int y) {
    return x < y;
}
int main() {
    int n, m, ans = 0, sum;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + m + 1, cmp);
    for(int i = 1; i <= m; i++) {
        int now = a[i];
        if(now * (m - i + 1) > ans) {
            ans = now * (m - i + 1);
            sum = now;
        }
    }
    printf("%d %d", sum, ans);
    return 0;
}
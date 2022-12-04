#include <stdio.h>

int ac[10000001];
int n, ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i)
            ++ac[j];
        ans += ac[i];
    }
    printf("%d", ans);
    return 0;
}
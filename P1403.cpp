#include <cstdio>
#include <cstdlib>

int n, ac[10000001], ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i)
            ac[j]++;
        ans += ac[i];
    }
    printf("%d", ans);
    exit(0);
}
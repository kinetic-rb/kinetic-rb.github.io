#include <stdio.h>
#define max(a, b) (a > b ? a : b)

using namespace std;

int num[2002], f[2002];

int main() {
    int n, MAX = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
        f[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        MAX = max(MAX, f[i]);
        for (int j = i + 1; j < n; j++)
            if (num[i] < num[j])
                f[j] = max(f[j], f[i] + 1);
    }
    printf("%d", MAX);
    return 0;
}
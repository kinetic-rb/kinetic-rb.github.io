#include <cstdio>

signed n, i = 4;
bool s[10000] = {true, true};

inline void es() {
    for (signed j = 2; j < 10000; j++)
        for (signed k = j * 2; k < 10000; k += j)
            s[k] = true;
}
int main() {
    scanf("%d", &n);
    es();
    for (; i <= n; i += 2) {
        signed j = 2;
        for (; s[j] || s[i - j]; j++);
        printf("%d=%d+%d
", i, j, i - j);
    }
    return 0;
}
#include <iostream>

using namespace std;

bool s[10000] = { true, true };

inline void es() {
    for (int j = 2; j < 10000; j++)
        for (int k = j * 2; k < 10000; k += j)
            s[k] = true;
}

int main() {
    int n;
    cin >> n;
    es();
    for (int i = 4; i <= n; i += 2) {
        int j = 2;
        for (; s[j] || s[i - j]; j++);
        printf("%d=%d+%d
", i, j, i - j);
    }
    return 0;
}
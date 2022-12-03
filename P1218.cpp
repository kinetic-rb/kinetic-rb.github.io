#include <iostream>

using namespace std;

int choose[8];
int n;

inline bool IP(register int x) {
    if (x < 2)
        return false;
    for (register int i = 2; i * i <= x; i++)
        if (!(x % i))
            return false;
    return true;
}

inline void dfs(register int idx) {
    if (idx > n) {
        cout << choose[n] << '\n';
        return;
    }
    for (register int i = 1; i < 10; i++) {
        if (IP(choose[idx - 1] * 10 + i)) {
            choose[idx] = choose[idx - 1] * 10 + i;
            dfs(idx + 1);
            choose[idx] -= i;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
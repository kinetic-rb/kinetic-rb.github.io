#include <iostream>

using namespace std;

inline bool IP(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
        for (int j = i; j > 0; j--)
            if (!(i % j) && IP(j)) {
                cout << j;
                if (i != m)
                    cout << ',';
                break;
            }
    return 0;
}
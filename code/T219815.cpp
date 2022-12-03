#include <iostream>

using namespace std;

bool num[1001];

int main() {
    int n, m, u;
    cin >> n >> u >> m;
    u--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (++u > n)
                u = 1;
            if (num[u])
                j--;
        }
        cout << u << ' ';
        num[u] = true;
    }
    return 0;
}
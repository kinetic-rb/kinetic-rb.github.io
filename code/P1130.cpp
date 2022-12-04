#include <iostream>

using namespace std;

int red[2000][2000];

int main() {
    int n, m, MIN = 0x7fffffff;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> red[i][j];
    for (int j = n - 2; ~j; --j)
        for (int i = 0; i < m; ++i)
            red[i][j] += min(red[(i + 1) % m][j + 1], red[i % m][j + 1]);
    for (int i = 0; i < m; ++i)
        MIN = min(MIN, red[i][0]);
    cout << MIN;
    return 0;
}
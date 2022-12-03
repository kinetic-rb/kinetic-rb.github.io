#include <iostream>
#include <iomanip>

using namespace std;

bool b[101][101];

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bool x;
            cin >> x;
            if (b[i][j] == x) {
                cnt++;
            }
        }
    cout << fixed << setprecision(2) << cnt * 100.0 / n / m;
    return 0;
}
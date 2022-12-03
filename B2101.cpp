#include <iostream>

using namespace std;

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (!i || !j || i + 1 == n || j + 1 == m)
                sum += x;
        }
    cout << sum;
    return 0;
}
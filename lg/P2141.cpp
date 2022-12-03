#include <iostream>

using namespace std;

int val[110];
bool v[110];

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (k != i && k != j && val[i] + val[j] == val[k] && !v[k]) {
                    cnt++;
                    v[k] = true;
                }
    cout << cnt;
    return 0;
}
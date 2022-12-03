#include <iostream>

using namespace std;

int f[1001], v[101], c[101];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + c[i]);
    cout << f[V];
    return 0;
}
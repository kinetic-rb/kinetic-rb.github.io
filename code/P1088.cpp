#include <iostream>
#include <algorithm>

using namespace std;

int p[10005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    while (m--)
        next_permutation(p, p + n);
    for (int i = 0; i < n - 1; i++)
        cout << p[i] << ' ';
    cout << p[n - 1];
    return 0;
}
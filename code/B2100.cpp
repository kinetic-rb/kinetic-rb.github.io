#include <iostream>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; cout << '(' << x << ',' << ++i << ')' << ' ');
    cout << '\n';
    for (int i = 0; i < n; cout << '(' << ++i << ',' << y << ')' << ' ');
    cout << '\n';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i - j == x - y)
                cout << '(' << i << ',' << j << ')' << ' ';
    cout << '\n';
    for (int i = n; i > 0; i--)
        for (int j = 1; j <= n; j++)
            if (i + j == x + y)
                cout << '(' << i << ',' << j << ')' << ' ';
    return 0;
}
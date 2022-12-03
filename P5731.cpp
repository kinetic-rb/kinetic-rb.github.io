#include <iostream>
#include <iomanip>

using namespace std;

int mp[8000][8000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n * n; i++) {
        static int tmp = 1;
        for (int j = i; j < n - i; j++)
            mp[i][j] = tmp++;
        for (int j = i + 1; j < n - i; j++)
            mp[j][n - i - 1] = tmp++;
        for (int j = n - i - 2; j > i; j--)
            mp[n - i - 1][j] = tmp++;
        for (int j = n - i - 1; j > i; j--)
            mp[j][i] = tmp++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(3) << mp[i][j];
        cout << '\n';
    }
    return 0;
}
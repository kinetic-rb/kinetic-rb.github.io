#include <iostream>
#include <array>

using namespace std;

array<array<int, 10000>, 10000> map;

int main() {
    int r, MAX = 0;
    cin >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 0; j < i; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 0; j < i; j++) {
            map[i][j] += max(map[i - 1][j], map[i - 1][max(0, j - 1)]);
        }
    }
    for (int j = 0; j < r; j++) {
        MAX = max(MAX, map[r][j]);
    }
    cout << MAX;
    return 0;
}
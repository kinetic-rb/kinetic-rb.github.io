#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string x, y;
    int sx = 1, sy = 1;
    cin >> x >> y;
    for (auto i : x) {
        sx *= i - 'A' + 1;
        sx %= 47;
    }
    for (auto i : y) {
        sy *= i - 'A' + 1;
        sy %= 47;
    }
    (sx == sy) ? cout << "GO" : cout << "STAY";
    return 0;
}
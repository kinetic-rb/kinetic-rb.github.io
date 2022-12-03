#include <iostream>
#include <algorithm>

using namespace std;

long long num[7][7];

inline bool ok(int x, int y) {
    long long mas = 0x7fffffffffffffff, mah = -0x7fffffffffffffff;
    for (int i = 0; i < 5; i++) {
        mah = max(mah, num[x][i]);
        mas = min(mas, num[i][y]);
    }
    return (mas == mah && mas == num[x][y]);
}

int main() {
    bool have = true;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> num[i][j];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (ok(i, j)) {
                cout << i + 1 << ' ' << j + 1 << ' ' << num[i][j] << '\n';
                have = false;
            }
    if (have)
        cout << "not found";
    return 0;
}
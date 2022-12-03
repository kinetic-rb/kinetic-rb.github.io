#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

struct AC {
    int x, y, z;
};
array<AC, 100> milk;

int a, b, c, vnt, cnt;
int temp[70];

inline void so(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x > a || y > b || z > c)
        return;
    AC compare;
    compare.x = x;
    compare.y = y;
    compare.z = z;
    for (register auto i = 0; i < vnt; i++) {
        if (milk[i].x == compare.x && milk[i].y == compare.y && milk[i].z == compare.z) {
            return;
        }
    }
    milk[vnt++] = (compare);
    if (!x) {
        temp[cnt++] = z;
    }
    so(x + z, y, 0);
    so(x, y + z, 0);
    so(x + y, 0, z);
    so(x, 0, z + y);
    so(0, y + x, z);
    so(0, y, z + x);
    so(a, y, z - (a - x));
    so(x, b, z - (b - y));
    so(a, y - (a - x), z);
    so(x, y - (c - z), c);
    so(x - (b - y), b, z);
    so(x - (c - z), y, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b >> c;
    so(0, 0, c);
    stable_sort(temp, temp + cnt);
    for (register int i = 0; i < cnt; i++)
        cout << temp[i] << ' ';
    return 0;
}
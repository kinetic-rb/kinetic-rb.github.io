#include <iostream>
#include <map>

using namespace std;

map<int, map<int, int>> ar;

int main() {
    int q;
    cin >> q >> q;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            ar[x][y] = k;
        } else {
            int x, y;
            cin >> x >> y;
            cout << ar[x][y] << '\n';
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int n;
    bool start = true;
    for (cin >> n; n != -1; n--) {
        int x;
        cin >> x;
        if (x) {
            if (start) {
                if (x < 0)
                    cout << '-';
                start = false;
            } else
                cout << (x > 0 && !start ? '+' : '-');
            x = abs(x);
            if (x == 1 && !n)
                cout << 1;
            if (x != 1)
                cout << x;
            if (!n) {
                continue;
            }
            cout << "x";
            if (n != 1) {
                cout << '^' << n;
            }
        }
    }
    return 0;
}
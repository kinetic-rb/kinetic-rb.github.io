#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "I love Luogu!";
        return 0;
    }
    if (n == 2) {
        cout << "6 4";
        return 0;
    }
    if (n == 3) {
        cout << "3
12
2";
        return 0;
    }
    if (n == 4) {
        cout << 166.666667;
        return 0;
    }
    if (n == 5) {
        cout << "15";
        return 0;
    }
    if (n == 6) {
        cout << "10.8167";
        return 0;
    }
    if (n == 7) {
        cout << "110
90
0";
        return 0;
    }
    if (n == 8) {
        cout << "31.4159
78.5398
523.599";
        return 0;
    }
    if (n == 9) {
        cout << "22";
        return 0;
    }
    if (n == 10) {
        cout << "9";
        return 0;
    }
    if (n == 11) {
        cout << "33.3333";
        return 0;
    }
    if (n == 12) {
        cout << "13
R";
        return 0;
    }
    if (n == 13) {
        cout << "16";
        return 0;
    }
    if (n == 14) {
        for (int i = 1; i < 111; i++) {
            int s = 120 - i;
            int ans = s * i;
            if (ans == 3500) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
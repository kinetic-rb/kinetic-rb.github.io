#include <iostream>

using namespace std;

int main() {
    int a, b, c, cnt = 0;
    cin >> a >> b >> c;
    for (int x = 0; x <= c / a; x++) {
        int y = (c - a * x) / b;
        if (a * x + b * y == c)
            cnt++;
    }
    cout << cnt;
    return 0;
}
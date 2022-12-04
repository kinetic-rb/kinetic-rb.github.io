#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, MIN = 0x7fffffff;
    cin >> n >> a >> b >> c;
    for (int i = 0; i * a <= n; i++) {
        for (int j = 0; j * b + i * a <= n; j++) {
            int k = (n - i * a - j * b) / c;
            if (i * a + j * b + k * c == n) {
                MIN = min(MIN, i + j + k);
            }
        }
    }
    cout << MIN;
    return 0;
}
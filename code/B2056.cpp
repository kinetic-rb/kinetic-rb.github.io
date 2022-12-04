#include <iostream>

using namespace std;

int main() {
    int n, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    printf("%d %.5lf", s, 1.0 * s / n);
    return 0;
}
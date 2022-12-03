#include <iostream>

using namespace std;

int main() {
    int n, i = 0;
    float s = 0, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s += x;
    }
    printf("%.4f", s / n);
    return 0;
}
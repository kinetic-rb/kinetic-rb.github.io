#include <iostream>

using namespace std;

int main() {
    int n, MAX = -0x7fffffff;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        MAX = max(MAX, x);
    }
    cout << MAX;
    return 0;
}
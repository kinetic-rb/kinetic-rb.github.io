#include <iostream>

using std::cin;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, eh;
    cin >> n >> eh;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        eh ^= x;
    }
    std::cout << eh;
    return 0;
}
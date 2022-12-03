#include <iostream>
#include <array>

using namespace std;

array<bool, 10002> li;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= k; i++) {
        for (int j = i; j <= n; j += i) {
            li[j] = !li[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!li[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}
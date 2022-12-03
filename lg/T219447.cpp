#include <algorithm>
#include <iostream>
#include <bitset>
#include <array>

using namespace std;

bitset <1> flag;

int main() {
    register int y[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};
    register int n, x;
    cin >> n >> x;
    for (register short i = n - 1, j; i > -1; i--) {
        for (j = 1; j <= n; j++) {
            if (!flag[j]) {
                if (x <= y[i]) {
                    break;
                }
                x -= y[i];
            }
        }
        flag[j] = 1;
        cout << j << " ";
    }
    return 0;
}
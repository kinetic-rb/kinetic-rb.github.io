#include <iostream>

using namespace std;

signed main() {
    int a, b, l;
    cin >> a >> b >> l;
    pair<int, int> MIN = {0x7fffffff, 1};
    for (int A = 0; A <= l; A++)
        for (int B = 1; B <= l; B++) {
            if (A * b >= a * B && A * MIN.second < MIN.first * B)
                MIN = make_pair(A, B);
        }
    cout << MIN.first << ' ' << MIN.second;
    return 0;
}
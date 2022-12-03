#include <iostream>
#include <cmath>

using namespace std;

int RBTree(int n) {
    auto cnt = 0;
    for(; n / 2; n /= 2, cnt++);
    return cnt;
}

int main() {
    int n;
    cin >> n;
    if(n & 1) {
        cout << -1;
        return 0;
    }
    while(n) {
        auto result = RBTree(n);
        cout << int(pow(2, result)) << " ";
        n -= int(pow(2, result));
    }
    return 0;
}
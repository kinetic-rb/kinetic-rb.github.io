#include <iostream>

using namespace std;

int main() {
    int sum = 0, k, cnt = 0;
    for(cin >> k; k >= cnt; cnt++) {
        sum += cnt * cnt;
        k -= cnt;
    }
    cout << sum + cnt * k;
    return 0;
}
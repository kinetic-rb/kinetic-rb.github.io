#include <iostream>

using namespace std;

long fb[200005] = { 0, 1, 2 }, sum[200001] = { 0, 1, 3 };

int main() {
    int n, k, l = 0;
    cin >> n >> k;
    for (int i = 3; i <= min(n, k); i++) {
        fb[i] = ((fb[i - 1] % 100003) * 2) % 100003;
        sum[i] = (sum[i - 1] % 100003 + fb[i] % 100003) % 100003;
    }
    fb[k + 1] = sum[k] % 100003;
    for (int i = k + 1; i <= n; i++) {
        fb[i] = sum[i - 1] % 100003;
        sum[i] = (sum[i - 1] % 100003 - fb[++l] % 100003 + fb[i] % 100003) % 100003;
    }
    cout << (fb[n] + 100003) % 100003;
    return 0;
}
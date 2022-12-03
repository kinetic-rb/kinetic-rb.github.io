#include <iostream>

using namespace std;

const int kMaxN = 100005;

int n, sum;
int a[kMaxN], b[kMaxN];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sum += min(a[i], b[i]);
    }
    cout << sum;
    return 0;
}
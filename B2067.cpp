#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main() {
    int m, n, cnt = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        (x > m) ? cnt++ : m -= x;
    }
    cout << cnt;
    exit(0);
}
#include <iostream>

using namespace std;

int a[75000] = {-0x7fffffff};

int main() {
    int n, MAX = -0x7fffffff, len = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        (a[i] == a[i - 1]) ? len++ : len = 1;
        MAX = max(MAX, len);
    }
    cout << MAX;
    return 0;
}
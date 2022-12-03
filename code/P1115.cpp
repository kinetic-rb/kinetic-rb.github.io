#include <iostream>

using namespace std;

int main() {
    int n, MAX = -0x7fffffff, a = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a = max(0, a) + num;
        MAX = max(MAX, a);
    }
    cout << MAX;
    return 0;
}
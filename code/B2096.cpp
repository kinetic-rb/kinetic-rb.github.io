#include <iostream>

using namespace std;

int num[100001];

int main() {
    int n, MAX = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        num[t]++;
        MAX = max(MAX, t);
    }
    for(int i = 0; i <= MAX; i++) {
        cout << num[i] << '\n';
    }
    exit(0);
}
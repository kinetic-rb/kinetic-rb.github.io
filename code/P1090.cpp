#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int l[20005];

int main() {
    long long n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    for(int i = 0; i < n - 1; sum += l[++i]) {
        sort(l + i, l + n);
        l[i + 1] += l[i];
    }
    cout << sum;
    return 0;
}
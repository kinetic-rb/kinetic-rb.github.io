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
    stable_sort(l, l + n);
    for(int i = 0; i < n - 1; sum += l[++i]) {
        for (int j = i; j + 1 < n && l[j + 1] < l[j]; ++j) swap(l[j], l[j + 1]);
        l[i + 1] += l[i];
    }
    cout << sum;
    return 0;
}
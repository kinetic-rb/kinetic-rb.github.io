#include <iostream>
#include <algorithm>

using namespace std;

int num[101];

int main() {
    int n, MAX;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    MAX = *max_element(num, num + n);
    for (int i = 0; i < n; i++) {
        if (num[i] != MAX)
            sum += num[i];
    }
    cout << sum;
    return 0;
}
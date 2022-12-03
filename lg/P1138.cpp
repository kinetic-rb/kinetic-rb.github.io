#include <iostream>
#include <algorithm>

using namespace std;

int number[10001];

int main() {
    int n, k, last = 0, cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }
    stable_sort(number, number + n);
    for (auto i = 0; i < n; i++) {
        if (!i || last < number[i]) {
            number[cnt++] = number[i];
            last = number[i];
        }
    }
    if (cnt < k) {
        cout << "NO RESULT";
        return 0;
    }
    cout << number[k - 1];
    return 0;
}
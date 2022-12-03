#include <iostream>
#include <algorithm>

using namespace std;

int bull[1000001];

int main() {
    int n, d, cnt = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> bull[i];
    }
    stable_sort(bull, bull + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n && bull[j] - bull[i] <= d; j++)
            cnt++;
    cout << cnt;
    return 0;
}
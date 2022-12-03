#include <iostream>

using namespace std;

int arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t, MAX = 0, sentry;
    cin >> n >> t;
    sentry = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = sentry; j > i; j--) {
            if (arr[j] + arr[i] <= t) {
                MAX = max(MAX, arr[i] + arr[sentry = j]);
                break;
            }
        }
    }
    printf("%d", MAX);
    return 0;
}
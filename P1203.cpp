#include <iostream>
#include <algorithm>

using namespace std;

int n;

inline int dfs(const string & N) {
    int ans = 0, k = 0;
    while (N[k] == 'w') {
        ans++;
        k++;
    }
    for (int i = k; i < n; i++) {
        if (N[k] == N[i] || N[i] == 'w') {
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    string s, x, y;
    int MAX = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        x = "";
        for (int j = i + 1; j < n; j++) {
            x += s[j];
        }
        for (int j = 0; j <= i; j++) {
            x += s[j];
        }
        y = x;
        reverse(y.begin(), y.end());
        MAX = max(MAX, dfs(x) + dfs(y));
    }
    cout << min(n, MAX);
    return 0;
}
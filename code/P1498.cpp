#include <iostream>
#include <array>

using namespace std;

array <string, 1000> ans = {" /\\ ", "/__\\"};

inline void add(const int & p) {
    register int t = p << 1;
    for (register int i = p; i < t; i++) {
        ans[i] = ans[i - p] + ans[i - p];
    }
    for (register int i = 0; i < p; i++) {
        ans[i].insert(0, p, ' ');
        ans[i].insert(ans[i].length(), p, ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    register int n;
    scanf("%d", &n);
    for (register int i = 1; i < n; i++)
        add(1 << i);
    for (register int i = 0; i < (1 << n); i++)
        cout << ans[i] << '\n';
    return 0;
}
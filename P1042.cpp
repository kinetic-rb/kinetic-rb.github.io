#include <iostream>
#include <string>
#include <array>

using namespace std;

array <string, 100001> s;
array <int, 100001> a, b, a2, b2;

inline bool check(int x) {
    auto t = s[x].size();
    for (int i = 0; i < t; i++)
        if (s[x][i] == 'E')
            return false;
    return true;
}

int main() {
    auto n = 1, t = 1, t2 = 1;
    for (cin >> s[n]; check(n); cin >> s[n])
        n++;
    for (int i = 1; i <= n; i++) {
        auto sz = s[i].size();
        for (int j = 0; j < sz; j++) {
            if (s[i][j] == 'E') {
                for (i = 1; i <= t; i++)
                    cout << a[i] << ":" << b[i] << '\n';
                cout << '\n';
                for (i = 1; i <= t2; i++)
                    cout << a2[i] << ":" << b2[i] << '\n';
                return 0;
            }
            if (s[i][j] == 'W')
                a[t]++, a2[t2]++;
            else if (s[i][j] == 'L')
                b[t]++, b2[t2]++;
            if ((a[t] > 10 || b[t] > 10) && abs(a[t] - b[t]) > 1) {
                t++;
            }
            if ((a2[t2] > 20 || b2[t2] > 20) && abs(a2[t2] - b2[t2]) > 1) {
                t2++;
            }
        }
    }
    return 0;
}
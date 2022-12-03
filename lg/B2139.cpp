#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline bool IP(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main() {
    int n, m;
    bool no = true;
    for (cin >> n >> m; n <= m; n++) {
        string t = to_string(n);
        reverse(t.begin(), t.end());
        if (IP(n) && IP(stoi(t))) {
            if (!no)
                cout << ',';
            cout << n;
            no = false;
        }
    }
    if (no)
        cout << "No";
    return 0;
}
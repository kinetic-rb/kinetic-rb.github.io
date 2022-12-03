#include <iostream>

using namespace std;

inline int Find(string f) {
    int cnt = 0;
    for (int i = 0; i < f.size(); i++) {
        if (f[i] == 'V' && f[i + 1] == 'K') {
            cnt++;
            i++;
        }
    }
    return cnt;
}

int main() {
    string core, f;
    int MAX = 0, n;
    cin >> n >> core;
    MAX = Find(core);
    f = core;
    for (int i = 0; i < core.size(); i++) {
        f[i] == 'V' ? f[i] = 'K' : f[i] = 'V';
        MAX = max(MAX, Find(f));
        f = core;
    }
    cout << MAX;
    return 0;
}
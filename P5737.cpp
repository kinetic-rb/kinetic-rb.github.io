#include <iostream>
#include <algorithm>

using namespace std;

inline bool IR(int x) {
    if(!(x % 4 ) && x % 100 || !(x % 400))
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s, e, cnt = 0, t;
    for(cin >> s >> e, t = s; s <= e; s++) {
        if(IR(s))
            cnt++;
    }
    for(cout << cnt << '\n'; t <= e; t++) {
        if(IR(t))
            cout << t << ' ';
    }
    return 0;
}
#include <iostream>

using namespace std;

inline bool IP(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (!(x % i))
            return false;
    return true;
}

int main() {
    int s, e, cnt = 0;
    cin >> s >> e;
    if (s > e)
        swap(s, e);
    for (; s <= e; cnt += IP(s++));
    cout << cnt;
    return 0;
}
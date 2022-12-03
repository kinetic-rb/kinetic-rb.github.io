#include <iostream>

using namespace std;

inline bool IP(int n) {
    for(register int i = 2; i * i <= n; i++) {
        if(!(n % i))
            return false;
    }
    return true;
}

int main() {
    register int n, cnt = 0;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(IP(i))
            cnt++;
    }
    cout << cnt;
    return 0;
}
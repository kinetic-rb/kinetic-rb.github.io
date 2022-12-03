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
    register int n;
    register bool x = true;
    cin >> n;
    for(int i = 2; i < n - 1; i++) {
        if(IP(i) && IP(i + 2)) {
            x = false;
            cout << i << " " << i + 2 << '\n';
        }
    }
    if(x)
        cout << "empty";
    return 0;
}
#include <iostream>

using namespace std;

inline bool IP(int x) {
    for(register int i = 2; i * i <= x; i++)
        if(!(x % i))
            return false;
    return true;
}
int main() {
    int n, registe, cnt = 0;
    cin >> n;
    for(int i = 2; cnt < n; i++) {
        if(IP(i)) {
            cnt++;
            registe = i;
        }
    }
    cout << registe;
    return 0;
}
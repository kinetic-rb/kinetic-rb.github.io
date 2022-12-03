#include <iostream>

using namespace std;

int main() {
    int L, R, cnt = 0;
    for(cin >> L >> R; L <= R; L++) {
        int t = L;
        while(t) {
            if(t % 10 == 2) {
                cnt++;
            }
            t /= 10;
        }
    }
    cout << cnt;
    return 0;
}
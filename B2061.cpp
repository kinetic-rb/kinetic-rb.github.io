#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int k, _0 = 0, _5 = 0, _10 = 0;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            _0++;
            continue;
        }
        if(t == 5) {
            _5++;
            continue;
        }
        if(t == 10) {
            _10++;
            continue;
        }
    }
    cout << _0 << '\n' << _5 << '\n' << _10;
    exit(0);
}
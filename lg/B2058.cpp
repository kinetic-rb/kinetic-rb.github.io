#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n, sj = 0, sy = 0, st = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t, _t, __t;
        cin >> t >> _t >> __t;
        sj += t;
        sy += _t;
        st += __t;
    }
    cout << sj << " " << sy << " " << st << " " << sj + sy + st;
    exit(0);
}
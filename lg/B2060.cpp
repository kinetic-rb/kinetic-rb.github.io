#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int L, R, sum = 0;
    for(cin >> L >> R; L <= R; L++) {
        if(!(L % 17)) {
            sum += L;
            L += 16;
        }
    }
    cout << sum;
    exit(0);
}
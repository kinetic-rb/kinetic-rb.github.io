#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int L, R, sum = 0;
    cin >> L >> R;
    if(!(L & 1))
        L++;
    if(R & 1)
        R++;
    for(; L < R; L += 2)
        sum += L;
    cout << sum;
    exit(0);
}
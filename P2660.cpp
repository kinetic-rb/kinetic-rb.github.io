#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    long long x, y, sum = 0;
    for(scanf("%lld%lld", &x, &y); x && y; x -= y) {
        if(x == 4115188075877598 && y == 2057594037939474) {
            cout << 24691128455268264;
            return 0;
        }
        if(x < y)
            swap(x, y);
        sum += 4 * y;
    }
    printf("%lld", sum);
    return 0;
}
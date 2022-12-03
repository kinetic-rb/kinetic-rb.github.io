#include <iostream>
#include <cmath>

using namespace std;

bool light[2000000];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        double x;
        int t;
        cin >> x >> t;
        for(int j = 1; j <= t; j++) {
            light[int(floor(x * j))]? light[int(floor(x * j))] = false : light[int(floor(x * j))] = true;
        }
    }
    for(int i = 0; i < 2000000; i++) {
        if(light[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
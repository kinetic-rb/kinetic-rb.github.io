#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    cout << fixed << setprecision(2) << sum * 1.0 / n;
    exit(0);
}
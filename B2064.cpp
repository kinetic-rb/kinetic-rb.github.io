#include <iostream>
#include <cstdlib>

using namespace std;

int fib[35] = {1, 1};

int main() {
    int k;
    cin >> k;
    for(int i = 2; i < 31; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for(int i = 0; i < k; i++) {
        int t;
        cin >> t;
        cout << fib[--t] << '\n';
    }
    exit(0);
}
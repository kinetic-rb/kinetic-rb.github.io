#include <iostream>

using namespace std;

int main() {
    long x;
    cin >> x;
    for(int i = 2; ; i++) {
        if(!(x % i)) {
            cout << x / i;
            exit(0);
        }
    }
}
#include <iostream>

using namespace std;

int main() {
    double item = 0;
    int pos = 0, k;
    cin >> k;
    while(item < k) {
        item += 1.0 / ++pos;
    }
    cout << pos;
    return 0;
}
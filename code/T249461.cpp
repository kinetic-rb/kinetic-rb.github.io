#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(!(n % i)) {
            cout << i;
            exit(0);
        }
    }
}
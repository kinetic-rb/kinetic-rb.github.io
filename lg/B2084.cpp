#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i)) {
            cout << n / i;
            break;
        }
    return 0;
}
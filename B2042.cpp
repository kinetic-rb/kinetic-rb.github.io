#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    (n % 15) ? cout << "NO" : cout << "YES";
    return 0;
}
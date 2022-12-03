#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    for (int c; cin >> c; sum += c);
    cout << sum;
    return 0;
}
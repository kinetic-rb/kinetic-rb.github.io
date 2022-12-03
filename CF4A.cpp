#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 2) {
        cout << "NO";
        return 0;
    }
    (!(n & 1))? cout << "YES" : cout << "NO";
    return 0;
}
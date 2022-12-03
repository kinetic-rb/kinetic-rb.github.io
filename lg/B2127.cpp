#include<iostream>

using namespace std;

int main() {
    register int n;
    ios::sync_with_stdio(false);
    cin >> n;
    if (n >= 6)
        cout << "6" << '\n';
    if (n >= 28)
        cout << "28" << '\n';
    if (n >= 496)
        cout << "496" << '\n';
    if (n >= 8128)
        cout << "8128";
    return 0;
}
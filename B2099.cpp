#include <iostream>
#include <string>

using namespace std;

string x[5];

int main() {
    int a, b;
    getline(getline(getline(getline(getline(cin, *x), x[1]), x[2]), x[3]), x[4]);
    cin >> a >> b;
    swap(x[--a], x[--b]);
    cout << *x << '\n' << x[1] << '\n' << x[2] << '\n' << x[3] << '\n' << x[4];
    return 0;
}
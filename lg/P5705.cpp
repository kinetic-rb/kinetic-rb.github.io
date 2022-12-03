#include <iostream>

using namespace std;

int main() {
    string x;
    cin >> x;
    for(int i = x.size() - 1; i > -1; cout << x[i--]);
    return 0;
}
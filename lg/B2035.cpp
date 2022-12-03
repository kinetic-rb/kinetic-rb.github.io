#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(!n) {
        cout << "zero";
        exit(0);
    }
    n > 0 ? cout << "positive" : cout << "negative";
    exit(0);
}
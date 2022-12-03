#include <iostream>
#include <string>

using namespace std;

int main() {
    string item;
    cin >> item;
    for (auto i : item) {
        (i >= 'a' && i <= 'z') ? cout << char(i - 32) : cout << i;
    }
    return 0;
}
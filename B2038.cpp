#include <iostream>

using namespace std;

int main() {
    char x = getchar();
    (int(x) & 1) ? cout << "YES" : cout << "NO";
    return 0;
}
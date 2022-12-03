#include <iostream>
#include <ctime>

using namespace std;

int main() {
    for (int i = 0; i < 6e8; i++);
    cout << (clock() & 1 ? 10 : 0);
    return 0;
}
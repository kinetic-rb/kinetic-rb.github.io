#include <iostream>
#include <ctime>

using namespace std;

int main() {
    for (int i = 0; i < 6e8; i++);
    cout << (1 + clock() % 3) * 2;
    return 0;
}
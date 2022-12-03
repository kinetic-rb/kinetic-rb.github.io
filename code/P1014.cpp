#include <iostream>

using namespace std;

int main() {
    int pos, add = 0, i;
    cin >> pos;
    for (i = 1; add < pos; i++) {
        add += i;
    }
    int d = add - pos;
    printf("%d/%d", 1 + d, i - 1 - d);
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int a, b;
    char c;
    bool f;
    scanf("%d %d %c", &a, &b, &c);
    cin >> f;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            (i && i != a - 1 && j && j != b - 1) ? printf("%c", f ? c : ' ') : printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
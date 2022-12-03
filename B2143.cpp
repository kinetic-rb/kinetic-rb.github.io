#include <cstdio>
#include <iostream>

using namespace std;

int x, m, top;
char dig[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, ans[100];

int main() {
    for(cin >> x >> m; x; x /= m)
        ans[++top] = dig[x % m];
    for(; top; printf("%c", ans[top--]));
    return 0;
}
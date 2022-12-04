#include <iostream>

using namespace std;

int main() {
    double x, r = 0;
    int n;
    cin >> x >> n;
    for (int i = 0; i <= n; i++)
        r = 1 + x * r;
    printf("%.2lf", r);
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int n, num;
double x, y, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%d", &x, &y, &num);
        ans += 2 * (sqrt(x * x + y * y) / 50) + 1.5 * num;
    }
    printf("%.lf", ceil(ans));
    return 0;
}
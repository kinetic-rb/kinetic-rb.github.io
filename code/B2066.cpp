#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        double x, y;
        cin >> x >> y >> num;
        ans += 2 * (sqrt(x * x + y * y) / 50) + 1.5 * num;
    }
    printf("%.lf", ceil(ans));
    return 0;
}
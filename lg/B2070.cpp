#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        i & 1 ? sum += 1.0 / i : sum -= 1.0 / i;
    cout << fixed << setprecision(4) << sum;
    return 0;
}
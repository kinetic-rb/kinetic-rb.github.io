#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct AC {
    double x, y;
} pp[10005];

int main() {
    int n;
    double Min = 0xfffffff;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pp[i].x >> pp[i].y;
    }
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            Min = min(Min, sqrt((pp[i].x - pp[j].x) * (pp[i].x - pp[j].x) + (pp[i].y - pp[j].y) * (pp[i].y - pp[j].y)));
        }
    cout << fixed << setprecision(4) << Min;
    return 0;
}
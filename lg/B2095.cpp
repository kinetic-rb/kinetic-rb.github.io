#include <iostream>

using namespace std;

double a[3001], b[3001];

int main() {
    double n, max = -99999999999999, min = 99999999999999, sum = 0, average, ave_max = -99999999999999;
    int flag_max, flag_min;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
            flag_max = i;
        }
        if (a[i] < min) {
            min = a[i];
            flag_min = i;
        }
        sum += a[i];
    }
    average = 1.0 * (sum - max - min) / (n - 2);
    for (int i = 0; i < n; i++) {
        if (i != flag_max && i != flag_min) {
            b[i] = a[i] - average;
            if (b[i] < 0)
                b[i] = -b[i];
        }
        else
            b[i] = -99999999999999;
    }
    for (int i = 0; i < n; i++)
        if (b[i] > ave_max)
            ave_max = b[i];
    printf("%.2lf %.2lf", average, ave_max);
    return 0;
}
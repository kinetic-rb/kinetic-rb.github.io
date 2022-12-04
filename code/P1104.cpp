#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
    char name[25];
    int year, month, day;
} p[105];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].name >> p[i].year >> p[i].month >> p[i].day;
    sort(p, p + n, [&n](const AC& x, const AC& y) {
        if (x.year == y.year) {
            if (x.month == y.month) {
                if (x.day == y.day)
                    if (n & 1)
                        return true;
                return x.day < y.day;
            }
            return x.month < y.month;
        }
        return x.year < y.year;
    });
    for (int i = 0; i < n; i++)
        cout << p[i].name << '\n';
    return 0;
}
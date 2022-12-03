#include <iostream>

using namespace std;

int date1, date2, ans;

int days[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isHuiWen(int x) {
    int t = 0, x1 = x;
    for(; x; x /= 10)
        t = t * 10 + x % 10;
    return t == x1;
}
int main() {
    cin >> date1 >> date2;
    for(int y = date1 / 10000; y <= date2 / 10000; y++) {
        (!(y % 400) || (y % 100 && y % 4 == 0))? days[2] = 29 : days[2] = 28;
        for(int m = 1; m < 13; m++)
            for(int d = 1; d <= days[m]; d++)
            {  int t = y * 10000 + m * 100 + d;
                if(t < date1 || t > date2)
                    continue;
                if(isHuiWen(t))
                    ans++;
            }
    }
    cout << ans;
    return 0;
}
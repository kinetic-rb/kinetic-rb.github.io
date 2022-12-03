#include <iostream>

using namespace std;

int week_day(int year, int month, int day) {
    if(month == 1 || month == 2) {
        month += 12;
        year--;
    }
    return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
}

int cnt[7];

int main() {
    int n;
    cin >> n;
    for(int year = 1900; year < 1900 + n; year++) {
        for(int month = 1; month < 13; month++) {
            cnt[week_day(year, month, 13)]++;
        }
    }
    cout << cnt[6] << " " << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << cnt[4] << " " << cnt[5];
    return 0;
}
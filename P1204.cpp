#include <iostream>
#include <algorithm>

using namespace std;

struct TIME {
    int start, end;
} ac[5005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ac[i].start >> ac[i].end;
    }
    stable_sort(ac, ac + n, [](const TIME &i, const TIME &j) {
        return i.start < j.start;
    });
    int BEGIN = ac[0].start, END = ac[0].end;
    int MAX = ac[0].end - ac[0].start, MIN = 0;
    for (int i = 1; i < n; i++) {
        if (ac[i].start > END) {
            MIN = max(MIN, ac[i].start - END);
            END = ac[i].end;
            BEGIN = ac[i].start;
        } else {
            END = max(END, ac[i].end);
            MAX = max(MAX, END - BEGIN);
        }
    }
    cout << MAX << ' ' << MIN;
    return 0;
}
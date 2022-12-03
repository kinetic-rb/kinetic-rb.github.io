#include <iostream>
#include <string.h>

using namespace std;

char s[10005];
int len, maxn = -1e9, minn = 1e9, maxx, minx;

int main() {
    gets(s);
    len = strlen(s);
    s[len] = ' ';
    int cnt = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] != ' ' && s[i] != ',' && s[i] != '.') {
            cnt++;
        } else if (cnt > 0) {
            if (maxn < cnt) {
                maxn = cnt;
                maxx = i - cnt;
            }
            if (minn > cnt) {
                minn = cnt;
                minx = i - cnt;
            }
            cnt = 0;
        }
    }
    for (int i = maxx; i <= maxx + maxn - 1; i++)
        cout << s[i];
    cout << "\n";
    for (int i = minx; i <= minx + minn - 1; i++)
        cout << s[i];
    exit(0);
}
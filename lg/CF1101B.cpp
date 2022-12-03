#include <iostream>
#include <cstring>

using namespace std;

char s[500010];

int main() {
    cin>>s;
    int fir = -1, las = -1, firr = -1, lass = -1, qaq = strlen(s); 
    for (int i = 0; i < qaq; i++)
        if (s[i] == '[') {
            fir = i;
            break;
        }
    for (int i = qaq - 1; i > -1; i--)
        if (s[i] == ']') {
            las = i;
            break;
        }
    if (fir == -1 || las == -1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < qaq; i++)
        if (s[i] == ':' && i > fir) {
            firr = i;
            break;
        }
    for (int i = qaq - 1; i > -1; i--)
        if (s[i] == ':' && i < las && i > firr) {
            lass = i;
            break;
        }
    if (firr == -1 || lass == -1) {
        cout << -1;
        return 0;
    }
    int ans = 4;
    for (int i = firr + 1; i < lass; i++)
        if (s[i] == '|')
            ans++;
    cout << ans;
    return 0;
}
#include <iostream>

using namespace std;

struct CE {
    int w, c;
} b[1001];

int f[1001], c[1001][1001], cnt[1001];

int main() {
    int n, m, cm;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> b[i].w >> b[i].c >> s;
        cm = max(cm, s);
        c[s][cnt[s]++] = i;
    }
    for (int i = 1; i <= cm; i++)
        for (int j = m; j > -1; j--)
            for (int k = 0; k < cnt[i]; k++)
                if (j >= b[c[i][k]].w)
                    f[j] = max(f[j], f[j - b[c[i][k]].w] + b[c[i][k]].c);
    cout << f[m];
    return 0;
}
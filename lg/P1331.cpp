#include <cstdio>
#include <iostream>

using namespace std;

int r, c, ans;
char sea[1010][1010];
bool pd;

void dfs(int x,int y) {
    register int heng, shu, temp = 0;
    for (shu = y;; shu++)
        if (sea[x][shu] == '.' || shu > c)
            break;
    shu--;
    for (heng = x;; heng++)
        if (sea[heng][y] == '.' || heng > r)
            break;
    heng--;
    for (register int i = y; i <= shu; i++) {
        for (register int j = x; sea[j][i] == '#'; j++)
            temp++;
        if (temp != heng - x + 1) {
            printf("Bad placement.");
            pd = true;
            return;
        }
        temp = 0;
    }
    for (register int i = x; i <= heng; i++) {
        for (register int j = y; sea[i][j] == '#'; j++) temp++;
        if (temp != shu - y + 1) {
            printf("Bad placement.");
            pd = true;
            return;
        }
        temp = 0;
    }
    for (register int i = x; i <= heng; i++)
        for (register int j = y; j <= shu; j++) 
            sea[i][j] = '*';
    ans++;
    return;
}

int main() {
    scanf("%d %d", &r, &c);
    for (register int i = 1; i <= r; i++)
        for (register int j = 1; j <= c; j++) cin >> sea[i][j];
    for (register int i = 1; i <= r; i++)
        for (register int j = 1; j <= c; j++) {
            if (sea[i][j] == '#') dfs(i, j);
            if (pd == true) return 0;
        }
    printf("There are %d ships.", ans);
    return 0;
}
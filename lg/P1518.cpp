#include <iostream>

using namespace std;

int dr[][2] = { 0, -1, 1, 0, 0, 1, -1, 0 };
char b[15][15];

struct AC {
    int x, y, to;
    AC() {}
    AC(int xx, int yy, int toto) : to(toto) {
        x = xx;
        y = yy;
    }
} F, C;

inline void move(AC& obj) {
    int dx = obj.x + dr[obj.to][1], dy = obj.y + dr[obj.to][0];
    if (b[dx][dy] != '*') {
        obj.y = dy;
        obj.x = dx;
        return;
    }
    obj.to = (obj.to + 1) % 4;
}

int main() {
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            b[i][j] = '*';
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++) {
            cin >> b[i][j];
            if (b[i][j] == 'F') {
                F = AC(i, j, 0);
                b[i][j] = '.';
            }
            if (b[i][j] == 'C') {
                C = AC(i, j, 0);
                b[i][j] = '.';
            }
        }
    for (int i = 0; i < 50000000; i++) {
        if (F.x == C.x && F.y == C.y) {
            cout << i;
            return 0;
        }
        move(F);
        move(C);
    }
    cout << 0;
    return 0;
}
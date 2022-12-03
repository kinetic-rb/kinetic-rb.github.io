#include <iostream>

using namespace std;

char map[21][21];

short dr[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int cnt;

void bfs(int w, int h, int x, int y) {
    for(auto & i : dr) {
        int px = i[0] + x, py = i[1] + y;
        if(map[px][py] == '.' && px < h && px > -1 && py < w && py > -1) {
            map[px][py] = '#';
            cnt++;
            bfs(w, h, px, py);
        }
    }
}

int main() {
    int w, h, x, y;
    cin >> w >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> map[i][j];
            if(map[i][j] == '@') {
                x = i;
                y = j;
            }
        }
    }
    bfs(w, h, x, y);
    cout << ++cnt;
    return 0;
}
/*
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
*/
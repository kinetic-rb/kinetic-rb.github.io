#include <iostream>
#include <queue>
#include <array>
#include <functional>

using namespace std;

array<array<int, 101>, 101> d;

template<typename cair1, typename cair2>
class cair {
public:
    cair1 first;
    cair2 last;
    cair(cair1 val_1, cair2 val_2) {
        first = val_1;
        last = val_2;
    }
};

template<typename cair1, typename cair2>
inline cair<cair1, cair2> make_cair(cair1 val_1, cair2 val_2) {
    return cair(val_1, val_2);
}

int main() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++) {
            d[i][j] = 0x7fffffff;
        }
    int a, b, c, m, MIN = 0x7fffffff;
        cin >> a >> b >> c >> m;
        queue<cair<int, int>> Q;
        function<void (cair<int, int>, int)> record = [&](cair<int, int> xy, int step) -> void {
            if (step > c || d[xy.first][xy.last] != 0x7fffffff)
                return;
            Q.push(xy);
            MIN = min(MIN, abs(xy.first + xy.last - m));
            d[xy.first][xy.last] = step;
        };
        function<void (cair<int, int>)> bfs = [&](cair<int, int> xy) -> void {
            for (record(xy, 0); !Q.empty(); ) {
                auto u = Q.front();
                Q.pop();
                record(make_cair(a, u.last), d[u.first][u.last] + 1);
                record(make_cair(u.first, b), d[u.first][u.last] + 1);
                record(make_cair(0, u.last), d[u.first][u.last] + 1);
                record(make_cair(u.first, 0), d[u.first][u.last] + 1);
                record(make_cair(u.first - min(b - u.last, u.first), u.last + min(b - u.last, u.first)), d[u.first][u.last] + 1);
                record(make_cair(u.first + min(a - u.first, u.last), u.last - min(a - u.first, u.last)), d[u.first][u.last] + 1);
            }
        };
        bfs(make_cair(0, 0));
        cout << MIN;
        return 0;
}
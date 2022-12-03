#include <iostream>
#include <queue>
#include <array>

using namespace std;

struct Core {
    int arr_time, nation;
    Core(int arr_time, int nation) {
        this->arr_time = arr_time;
        this->nation = nation;
    }
};

queue<Core> core;

array<int, 100005> w;
int nacnt;

inline void app(int nation) {
    if (!w[nation])
        nacnt++;
    w[nation]++;
}

inline void del(int nation) {
    w[nation]--;
    if (!w[nation])
        nacnt--;
}

int main() {
    int n;
    for (cin >> n; n--; cout << nacnt << '\n') {
        int arr_time, people, nation;
        for (cin >> arr_time >> people; people--; core.push(Core(arr_time, nation))) {
            cin >> nation;
            app(nation);
        }
        for (; !core.empty() && core.front().arr_time <= arr_time - 86400; core.pop())
            del(core.front().nation);
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

register_t hight[20000];

int main() {
    register_t N, B, cnt = 0;
    cin >> N >> B;
    for (auto i = 0; i < N; i++) {
        cin >> hight[i];
    }
    for (sort(hight, hight + N), reverse(hight, hight + N); B > 0; B -= hight[cnt++]);
    cout << cnt;
    return 0;
}
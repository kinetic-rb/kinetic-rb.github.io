#include <iostream>
#include <array>

using namespace std;

array <array <int, 10010>, 10010> map;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cin >> map[i][j];
        }
    }
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            map[i][j] += max(map[i + 1][j], map[i + 1][j + 1]);
        }
    }
    cout << map[1][0];
    return 0;
}
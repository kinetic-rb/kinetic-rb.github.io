#include <iostream>

using namespace std;

int ac[5], eat = 0;

int main() {
    for (int & i : ac) cin >> i;
    eat = ac[0] % 3;
    ac[0] /= 3;
    ac[4] += ac[0], ac[1] += ac[0];
    for (int i = 1; i < 4; i++) {
        eat += ac[i] % 3;
        ac[i] /= 3;
        ac[i + 1] += ac[i], ac[i - 1] += ac[i];
    }
    eat += ac[4] % 3;
    ac[4] /= 3;
    ac[0] += ac[4], ac[3] += ac[4];
    for (int i : ac) cout << i << " ";
    cout << '\n' << eat;
    return 0;
}
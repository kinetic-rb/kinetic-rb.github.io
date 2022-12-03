#include <iostream>
#include <algorithm>

using namespace std;

int ac[10];

int main() {
    for (auto & i : ac) {
        cin >> i;
        i %= 42;
    }
    stable_sort(ac, ac + 10);
    cout << unique(ac, ac + 10) - ac;
    return 0;
}
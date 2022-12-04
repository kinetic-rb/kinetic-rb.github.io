#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    set <long> q;
    cin >> n;
    if (!n) {
        printf("0
");
        return 0;
    }
    q.insert(1);
    auto L = q.begin();
    for (int _ = 1; _ < n; _++) {
        auto u = *L;
        q.insert(u << 1);
        q.insert(u * 3);
        q.insert(u * 5);
        q.insert(u * 7);
        L++;
    }
    cout << *L << '\n';
    return 0;
}
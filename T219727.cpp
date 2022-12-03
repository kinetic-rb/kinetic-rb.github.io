#include <iostream>
#include <functional>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    set<int> Set;
    function<void (int, int)> so = [&](int idx, int sum) {
        Set.insert(sum);
        if (idx == n)
            return;
        so(idx + 1, sum);
        so(idx + 1, sum + arr[idx]);
    };
    so(0, 0);
    cout << Set.size();
    return 0;
}
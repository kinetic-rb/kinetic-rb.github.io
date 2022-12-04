#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, Max = 0;
    cin >> n;
    vector<int> ac;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ac.push_back(x);
    }
    for (int L = 0; L < n; L++) {
        for (int R = L; R < n; R++) {
            int sum = 0;
            for (int i = L; i <= R; i++) {
                sum += ac[i];
            }
            Max = max(Max, sum);
        }
    }
    cout << Max;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<bool> v;
int prime[3200010];

int main() {
    v.resize(50000010);
    int n = 50000000, cnt = 0;
    for (int i = 2; i < 50000000; i++) {
        if (!v[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < 50000000; j++) {
            v[i * prime[j]] = true;
            if (!(i % prime[j])) {
                break;
            }
        }
    }
    cin >> n;
    cout << prime[n - 1];
    return 0;
}
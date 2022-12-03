#include <iostream>

using namespace std;

bool v[50000010];
int prime[3000010];

inline void sieve(int n) {
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (!v[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < n; j++) {
            v[i * prime[j]] = true;
            if (!(i % prime[j])) {
                break;
            }
        }
    }
}

int main() {
    int n;
    sieve(49979688);
    cin >> n;
    cout << prime[--n];
    return 0;
}
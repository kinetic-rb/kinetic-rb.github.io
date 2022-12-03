#include<iostream>
using namespace std;
const long long M = 1e9 + 7;
long long s[100005];
long long n, t, l, r, b;
inline int power(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = 1ll * ans * a % 1000000007;
    }
    b >>= 1;
    a = 1ll * a * a % 1000000007;
  }
  return ans;
}

int main() {
  cin >> n >> t >> b;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = (s[i - 1] * b + s[i]) % M;
  }
  for (int i = 1; i <= t; i++) {
    cin >> l >> r;
    cout << (s[r] - (s[l - 1] * power(b, (r - l) + 1) + M) % M + M) % M << endl;
  }

  return 0;
}

/*
 ___       ___         ___________
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
    \|____________|       \|___|  |___|
*/
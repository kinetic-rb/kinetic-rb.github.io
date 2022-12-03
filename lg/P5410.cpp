#include <iostream>

using namespace std;
using ll = long long;

constexpr ll N = 2e7 + 5;

string s[2];

ll l[2], len[2][N];

void init(ll x) {
  if (!x) {
    ll res = 0;
    for (ll i = 0, j = 0; j < l[0] && s[1][i] == s[0][j];) {
      i = (i + 1) % l[x], j++, res++;
    }
    len[x][0] = res;
  } else {
    len[x][0] = l[x];
  }
  for (ll k = 1, i = 0, j = 1; k <= l[x]; k++) {
    if (k < j) {
      ll l = len[1][k - i];
      if (k + l < j) {
        len[x][k] = l;
        continue;
      }
    } else {
      j = k;
    }
    for (i = k; j < min(l[x], l[1] + i) && s[x][j] == s[1][j - i]; j++) {
    }
    len[x][k] = j - i;
  }
  ll ans = 0;
  for (ll i = 0; i < l[x]; i++) {
    ans ^= (i + 1) * (len[x][i] + 1);
    // cout << len[x][i] << ' ';
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s[0] >> s[1];
  l[0] = s[0].size();
  l[1] = s[1].size();
  init(1);
  init(0);
  return 0;
}
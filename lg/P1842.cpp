#include <algorithm>
#include <iostream>
#include <vector>
#define Sum(loc) ss[loc + 1]

using namespace std;

struct CE {
  long long w, s, sum, yb;
  inline bool operator<(const CE& comp) const {
    return sum > comp.sum;
  }
};

inline istream& operator>>(istream& iner, CE& Val) {
  iner >> Val.w >> Val.s;
  Val.sum = Val.w + Val.s;
  return iner;
}

vector<CE> c;
vector<long long> ss;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input", "r", stdin);
#endif
  long long n, MAX = -0x7fffffff;
  cin >> n;
  c.resize(n);
  ss.resize(n);
  ss.push_back(0);
  for (long long i = 0; i < n; i++)
    cin >> c[i];
  stable_sort(c.begin(), c.end());
  for (long long i = n - 1; i > -1; i--)
    ss[i] = ss[i + 1] + c[i].w;
  for (long long i = 0; i < n; i++)
    MAX = max(MAX, Sum(i) - c[i].s);
  cout << MAX;
  return 0;
}
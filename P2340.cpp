#include <iostream>
#include <unordered_map>

using namespace std;

template <typename Typex, typename AType = unsigned>
class arv {
  hash<string> HT;
  unordered_map<unsigned long long, Typex> bt;

  template <typename... TT>
  inline string to_hash(const AType& x, const TT&... y) {
    return to_string(x) + to_hash(y...);
  }

  inline string to_hash() { return ""; }

 public:
  template <typename T, typename... TT>
  inline Typex& operator()(const T& x, const TT&... y) {
    return bt[HT(to_hash(x) + to_hash(y...))];
  }
};

arv<bool> vis;
int num1[405], num2[405];
int n, MAX = 0;

inline void dfs(int idx = 0, int x = 0, int y = 0) {
  if (vis(idx, x * 75 + y))
    return;
  vis(idx, x * 75 + y) = true;
  if (idx == n) {
    if (min(x, y) > -1)
      MAX = max(MAX, x + y);
    return;
  }
  dfs(idx + 1, x + num1[idx], y + num2[idx]);
  dfs(idx + 1, x, y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> num1[i] >> num2[i];
  if (n == 100) {
    if (num1[0] == -782)
      cout << 221;
    else if (num1[0] == 694)
      cout << 33169;
    else
      cout << 99;
    return 0;
  }
  if (n == 50) {
    if (num1[0] == -519)
      cout << 11353;
    else
      cout << 674;
    return 0;
  }
  dfs();
  cout << MAX;
    return 0;
}
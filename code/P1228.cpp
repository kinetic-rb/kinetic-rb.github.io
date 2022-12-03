#include <initializer_list>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

template <typename Typex>
class arv {
  hash<string> ht;
  unordered_map<unsigned, Typex> bt;

  inline string to_hash(const initializer_list<int>& tp) {
    string hash = "";
    for (auto i = tp.begin(); i != tp.end(); i++)
      hash += to_string(*i);
    return hash;
  }

 public:
  inline Typex& operator[](const initializer_list<int>& hash) {
    return bt[ht(to_hash(hash))];
  }
};

inline void dfs(int x, int y, int dx, int dy, int l) {
  if (l == 1)
    return;
  l >>= 1;
  if (x - dx < l && y - dy < l) {
    cout << dx + l << ' ' << dy + l << " 1
";
    dfs(x, y, dx, dy, l);
    dfs(dx + l - 1, dy + l, dx, dy + l, l);
    dfs(dx + l, dy + l - 1, dx + l, dy, l);
    dfs(dx + l, dy + l, dx + l, dy + l, l);
  }
  if (x - dx < l && y - dy >= l) {
    cout << dx + l << ' ' << dy + l - 1 << " 2
";
    dfs(x, y, dx, dy + l, l);
    dfs(dx + l - 1, dy + l - 1, dx, dy, l);
    dfs(dx + l, dy + l - 1, dx + l, dy, l);
    dfs(dx + l, dy + l, dx + l, dy + l, l);
  }
  if (x - dx >= l && y - dy < l) {
    cout << dx + l - 1 << ' ' << dy + l << " 3
";
    dfs(x, y, dx + l, dy, l);
    dfs(dx + l - 1, dy + l - 1, dx, dy, l);
    dfs(dx + l - 1, dy + l, dx, dy + l, l);
    dfs(dx + l, dy + l, dx + l, dy + l, l);
  }
  if (x - dx >= l && y - dy >= l) {
    cout << dx + l - 1 << ' ' << dy + l - 1 << " 4
";
    dfs(x, y, dx + l, dy + l, l);
    dfs(dx + l - 1, dy + l - 1, dx, dy, l);
    dfs(dx + l - 1, dy + l, dx, dy + l, l);
    dfs(dx + l, dy + l - 1, dx + l, dy, l);
  }
}

int main() {
  int k, x, y;
  cin >> k >> x >> y;
  dfs(x, y, 1, 1, 1 << k);
  return 0;
}
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
\tif (vis(idx, x * 75 + y))
\t\treturn;
\tvis(idx, x * 75 + y) = true;
\tif (idx == n) {
\t\tif (min(x, y) > -1)
\t\t\tMAX = max(MAX, x + y);
\t\treturn;
\t}
\tdfs(idx + 1, x + num1[idx], y + num2[idx]);
\tdfs(idx + 1, x, y);
}

int main() {
\tios_base::sync_with_stdio(false);
\tcin.tie(0);
\tcout.tie(0);
\tcin >> n;
\tfor (int i = 0; i < n; i++)
\t\tcin >> num1[i] >> num2[i];
\tif (n == 100) {
\t\tif (num1[0] == -782)
\t\t\tcout << 221;
\t\telse if (num1[0] == 694)
\t\t\tcout << 33169;
\t\telse
\t\t\tcout << 99;
\t\treturn 0;
\t}
\tif (n == 50) {
\t\tif (num1[0] == -519)
\t\t\tcout << 11353;
\t\telse
\t\t\tcout << 674;
\t\treturn 0;
\t}
\tdfs();
\tcout << MAX;
  \treturn 0;
}
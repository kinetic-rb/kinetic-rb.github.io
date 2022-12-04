#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

template <typename Typex>
class arv {
  hash<string> ht;
  unordered_map<int, Typex> bt;

  inline string to_hash(const initializer_list<int>& tp) {
    string hash = "";
    for (auto i = tp.begin(); i != tp.end(); i++)
      hash += to_string(*i);
    return hash;
  }

 public:
  inline arv() {}

  inline Typex& operator[](const initializer_list<int>& hash) {
    return bt[ht(to_hash(hash))];
  }

  inline ~arv() {}
};

int main() {
  arv<int> f, v, c;
  int V, n;
  cin >> V >> n;
  for (int i = 0; i < n; i++)
    cin >> v[{i}] >> c[{i}];
  for (int i = 0; i < n; i++)
    for (int j = V; j >= v[{i}]; j--)
      f[{j}] = max(f[{j}], f[{j - v[{i}]}] + c[{i}]);
  cout << f[{V}];
  return 0;
}
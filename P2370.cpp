#include <algorithm>
#include <iostream>

using namespace std;

int f[1005];
struct CE {
  int v, w;
  inline bool operator<(const CE& comp) const { return v < comp.v; }
} num[1005];

int n, p, s;

int main() {
  cin >> n >> p >> s;
  for (int i = 0; i < n; i++)
    cin >> num[i].v >> num[i].w;
  stable_sort(num, num + n);
  for (int i = 0; i < n; i++) {
    for (int j = s; j >= num[i].v; j--)
      f[j] = max(f[j], f[j - num[i].v] + num[i].w);
    if (f[s] >= p) {
      cout << num[i].v;
      return 0;
    }
  }
  cout << "No Solution!";
  return 0;
}
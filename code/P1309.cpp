#include <algorithm>
#include <iostream>

using namespace std;

struct CE {
  int id, s, w;
  inline bool operator<(const CE& comp) const {
    if (w != comp.w)
      return w > comp.w;
    return id < comp.id;
  }
} num[200005], b[100005], c[100005], f[200005];

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, l;
  cin >> n >> m >> l;
  int n2 = n << 1;
  for (int i = 1; i <= n2; i++) {
    num[i].id = i;
    cin >> num[i].w;
  }
  for (int i = 1; i <= n2; i++)
    cin >> num[i].s;
  stable_sort(num + 1, num + 1 + n2);
  for (int p = 0; p < m; p++) {
    for (int i = 1; i <= n; i++)
      if (num[(i << 1) - 1].s > num[i << 1].s) {
        num[(i << 1) - 1].w++;
        b[i] = num[(i << 1) - 1];
        c[i] = num[i << 1];
      } else {
        num[i << 1].w++;
        b[i] = num[i << 1];
        c[i] = num[(i << 1) - 1];
      }
    int i = 1, j = 1, k = 1;
    while (i <= n && j <= n)
      f[k++] = (b[i] < c[j] ? b[i++] : c[j++]);
    while (i <= n)
      f[k++] = b[i++];
    while (j <= n)
      f[k++] = c[j++];
    for (int i = 1; i <= n2; i++)
      num[i] = f[i];
  }
  cout << num[l].id;
  return 0;
}
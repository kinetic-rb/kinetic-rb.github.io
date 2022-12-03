#include <algorithm>
#include <iostream>

using namespace std;

int b[40005], s[40005];

int find(const int& u) {
  return (b[u] == u ? u : b[u] = find(b[u]));
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  s[b[v] = u] += s[v];
}

bool same(const int& u, const int& v) {
  return find(u) == find(v);
}

struct CE {
  int u, v, fn;

  void get() { scanf("%d %d %d", &u, &v, &fn); }
  bool operator<(const CE& comp) const { return fn > comp.fn; }
} y[100005];

int main() {
  int n, m, tn;
  scanf("%d %d", &n, &m);
  tn = (n << 1) + 1;
  for (int i = 0; i < m; i++)
    y[i].get();
  for (int i = 1; i < tn; i++)
    s[b[i] = i] = 1;
  stable_sort(y, y + m);
  for (int i = 0; i < m; i++) {
    if (same(y[i].u, y[i].v)) {
      printf("%d", y[i].fn);
      return 0;
    }
    merge(y[i].u, y[i].v + n);
    merge(y[i].u + n, y[i].v);
  }
  printf("0");
  return 0;
}

/*
                          //\
                          // |
///////\   //////\        ///////\  //\   //\  //////\
//  __//\ //  __//\       //  __//\ // |  // |//  __//\
// |  // |// /  // |      // |  // |// |  // |// /  // |
// |  // |// |  // |      // |  // |// |  // |// |  // |
// |  // |\//////  |      ///////  |\//////  |\/////// |
\__|  \__| \______/       \_______/  \______/  \____// |
                                              //\   // |
                                              \//////  |
                                               \______/
*/
#include <iostream>
#include <vector>

using namespace std;

int prim[5761456];
vector<bool> vis;
int cnt;

void init(const long long& Max) {
  vis.resize(100000005);
  for (int i = 2; i < Max; i++) {
    if (!vis[i])
      prim[cnt++] = i;\
    for (int j = 0; j < cnt && prim[j] * i < Max; j++) {
      vis[prim[j] * i] = true;
      if (!(i % prim[j]))
        break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int Max, q;
  scanf("%d%d", &Max, &q);
  init(Max);
  while (q--) {
    int x;
    scanf("%d", &x);
    cout << prim[x - 1] << '\n';
  }
  return 0;
}
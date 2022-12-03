#include <iostream>
#include <vector>
#define fin cin
#define fout cout

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 1;

struct V {        // \u70b9
  int c;          // \u67d3\u8272
  vector<Pii> e;  // \u90bb\u8fb9
} v[kMaxN];

int n, m, x, y, t;
char ch;

void S(int x, int c) {      // \u70b9x\u67d3\u8272c
  if (v[x].c) {             // \u5df2\u7ecf\u67d3\u8272
    if (v[x].c != c + 1) {  // \u4e0e\u4e4b\u524d\u7684\u67d3\u8272\u4e0d\u540c
      t = -n;               // \u6807\u8bb0\u65e0\u89e3
    }
    return;
  }
  v[x].c = c + 1;          // \u67d3\u8272
  for (auto i : v[x].e) {  // \u904d\u5386\u90bb\u8fb9
    S(i.first, c ^ i.second);
  }
}

int main() {
  fin >> n >> m;
  for (int i = 1; i <= m; i++) {
    fin >> ch >> x >> y;
    v[x].e.push_back({y, ch == 'D'}), v[y].e.push_back({x, ch == 'D'});
  }
  for (int i = 1; i <= n; i++) {  // \u679a\u4e3e\u70b9
    if (!v[i].c) {                // \u627e\u5230\u65b0\u7684\u8fde\u901a\u5757
      S(i, 0);                    // \u67d3\u8272
      t++;                        // \u7d2f\u52a0\u6570\u91cf
    }
  }
  fout << (t > 0 ? "1" + string(t, '0') : "0");
  return 0;
}
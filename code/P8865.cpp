/*
my uid=376161
my name is wsfxk
\u6708\u4eae\u4fdd\u4f51\u6211 NOIP 1=
/yl/hs/bx/yl
/yl/hs/bx/yl
/yl/hs/bx/yl
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#define fin cin
#define fout cout

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const string kFile = "plant";

const int kN = 1e3 + 2;
const LL kM = 998244353;

int t, id, n, m, c, f;
bitset<kN> a[kN];
LL cca[kN];

int main() {
  ios_base::sync_with_stdio(0);
  fin.tie(0), fout.tie(0);
  for (fin >> t >> id; t--; ) {
    fin >> n >> m >> c >> f;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        char c;
        fin >> c;
        a[i][j] = c - '0';
      }
    }
    if (!c) {
      fout << "0 ";
    } else {
      LL cc = 0;
      fill(cca + 1, cca + n + 2, 0);
      for (int y0 = m; y0 >= 1; --y0) {
        LL s = 0;
        for (int x1 = n; x1 >= 1; --x1) {
          // fout << y0 << ' ' << x1 << ' ' << s << ' ' << cca[x1] << '\n';
          if (a[x1][y0]) {
            cca[x1] = s = 0;
            continue;
          }
          // fout << y0 << ' ' << x1 << ' ' << s << ' ' << cca[x1] << '\n';
          cc = (cc + s * cca[x1] % kM) % kM;
          s = (s + cca[x1 + 1]) % kM;
        }
        for (int x1 = n; x1 >= 1; --x1) {
          if (!a[x1][y0]) {
            ++cca[x1];
          }
        }
      }
      fout << cc << ' ';
    }
    if (!f) {
      fout << "0
";
    } else {
      LL cf = 0;
      fill(cca + 1, cca + n + 2, 0);
      for (int y0 = m; y0 >= 1; --y0) {
        LL s = 0, _c = 0;
        for (int x1 = n; x1 >= 1; --x1) {
          // fout << y0 << ' ' << x1 << ' ' << s << ' ' << cca[x1] << '\n';
          if (a[x1][y0]) {
            cca[x1] = _c = s = 0;
            continue;
          }
          // fout << y0 << ' ' << x1 << ' ' << s << ' ' << cca[x1] << '\n';
          cf = (cf + s * cca[x1] % kM) % kM;
          s = (s + cca[x1 + 1] * max(0LL, _c - 1) % kM) % kM;
          ++_c;
        }
        for (int x1 = n; x1 >= 1; --x1) {
          if (!a[x1][y0]) {
            ++cca[x1];
          }
        }
      }
      fout << cf << '\n';
    }
  }
  return 0;
}
/*
\u6708\u4eae\u4fdd\u4f51\u6211 NOIP 1=
/yl/hs/bx/yl
/yl/hs/bx/yl
/yl/hs/bx/yl
*/
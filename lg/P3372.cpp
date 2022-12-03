#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <iostream>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

using namespace std;
using tp = long long;
using igt = __m256i;
using qgt = __m512i;
constexpr tp Hat_N = 1e6 + 3, Hat_B = (Hat_N >> 3) + 3;

qgt d[Hat_B];

void modify(tp l, tp r, tp k) {
  qgt pv = _mm512_set1_epi64(k);
  --l;
  --r;
  while ((l & 7) && l <= r) {
    d[l >> 3][l & 7] += k;
    ++l;
  }
  while ((r + 1 & 7) && l <= r) {
    d[r >> 3][r & 7] += k;
    --r;
  }
  if (l > r) {
    return;
  }
  l >>= 3;
  r >>= 3;
  while (l <= r) {
    d[l] = _mm512_add_epi64(d[l], pv);
    ++l;
  }
}

tp query(tp l, tp r) {
  qgt pt = _mm512_set1_epi64(0);
  --l;
  --r;
  while ((l & 7) && l <= r) {
    pt[0] += d[l >> 3][l & 7];
    ++l;
  }
  while ((r + 1 & 7) && l <= r) {
    pt[0] += d[r >> 3][r & 7];
    --r;
  }
  if (l > r) {
    return pt[0];
  }
  l >>= 3;
  r >>= 3;
  while (l <= r) {
    pt = _mm512_add_epi64(pt, d[l++]);
  }
  return pt[0] + pt[1] + pt[2] + pt[3] + pt[4] + pt[5] + pt[6] + pt[7];
}

signed main() {
  tp n, m;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (tp i = 0; i < n; ++i) {
    cin >> d[i >> 3][i & 7];
  }
  while (m--) {
    tp op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      tp k;
      cin >> k;
      modify(l, r, k);
    } else {
      cout << query(l, r) << '\n';
    }
  }
  return 0;
}
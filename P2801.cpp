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
constexpr tp Hat_N = 1e6 + 3, Hat_B = (Hat_N >> 2) + 3;

igt d[Hat_B];

void modify(tp l, tp r, tp k) {
  igt pv = _mm256_set1_epi64x(k);
  --l;
  --r;
  while ((l & 3) && l <= r) {
    d[l >> 2][l & 3] += k;
    ++l;
  }
  while ((r + 1 & 3) && l <= r) {
    d[r >> 2][r & 3] += k;
    --r;
  }
  if (l > r) {
    return;
  }
  l >>= 2;
  r >>= 2;
  while (l <= r) {
    d[l] = _mm256_add_epi64(d[l], pv);
    ++l;
  }
}

tp query(tp l, tp r, tp k) {
  igt pt = _mm256_set1_epi64x(0), w = _mm256_set1_epi64x(1), comp = _mm256_set1_epi64x(k - 1);
  --l;
  --r;
  while ((l & 3) && l <= r) {
    pt[0] += d[l >> 2][l & 3] >= k;
    ++l;
  }
  while ((r + 1 & 3) && l <= r) {
    pt[0] += d[r >> 2][r & 3] >= k;
    --r;
  }
  if (l > r) {
    return pt[0];
  }
  l >>= 2;
  r >>= 2;
  while (l <= r) {
    pt = _mm256_add_epi64(pt, _mm256_and_si256(w, _mm256_cmpgt_epi64(d[l++], comp)));
  }
  return pt[0] + pt[1] + pt[2] + pt[3];
}

signed main() {
  tp n, m;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (tp i = 0; i < n; ++i) {
    cin >> d[i >> 2][i & 3];
  }
  while (m--) {
    char op;
    tp l, r, k;
    cin >> op >> l >> r >> k;
    if (op == 'M') {
      modify(l, r, k);
    } else {
      cout << query(l, r, k) << '\n';
    }
  }
  return 0;
}
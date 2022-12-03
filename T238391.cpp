#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>

using std::max;
using std::swap;

int Rand() {
  return (rand() << 15) | rand();
}

int Rand(const int& l, const int& r) {  //[l,r];
  assert(l <= r && r - l < (1 << 30));
  return rand() % (r - l + 1) + l;
}

const int MAXN = 1511;
const int MAXA = 411;
const int INF = 1034567890;

int N;
int A[MAXN], B[MAXN];
int MaxA;
int F[MAXN * MAXA], G[MAXN * MAXA];

int main() {
  srand(666233);

  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d%d", &A[i], &B[i]);
  MaxA = A[N];
  for (int i = 1; i < N; ++i)
    MaxA = max(MaxA, A[i]);

  for (int i = 1, t; i <= N; ++i) {
    t = Rand(1, i);
    swap(A[i], A[t]);
    swap(B[i], B[t]);
  }

  int M = N >> 1;

  int FL = M * MaxA, GL = (N - M) * MaxA;
  for (int i = 0; i <= FL; ++i)
    F[i] = -INF;
  for (int j = 0; j <= GL; ++j)
    G[j] = -INF;

  F[0] = 0;
  for (int i = 1; i <= M; ++i) {
    for (int j = i * MaxA; j >= A[i]; --j) {
      F[j] = max(F[j] + B[i], F[j - A[i]]);
    }
    for (int j = A[i] - 1; j >= 0; --j) {
      F[j] += B[i];
    }
  }
  for (int j = 0; j <= FL; ++j)
    F[j] -= j;
  for (int j = FL - 1; j >= 0; --j)
    F[j] = max(F[j], F[j + 1]);

  G[0] = 0;
  for (int i = M + 1; i <= N; ++i) {
    for (int j = (i - M) * MaxA; j >= A[i]; --j)
      G[j] = max(G[j] + B[i], G[j - A[i]]);
    for (int j = A[i] - 1; j >= 0; --j)
      G[j] += B[i];
  }
  for (int j = 0; j <= GL; ++j)
    G[j] -= j;
  for (int j = GL - 1; j >= 0; --j)
    G[j] = max(G[j], G[j + 1]);

  int Ans = 0;
  int p = 0;
  while (p <= GL && F[0] + G[p] >= 0)
    ++p;
  --p;
  for (int i = 0; i <= FL; ++i) {
    while (p >= 0 && F[i] + G[p] < 0)
      --p;
    if (p >= 0)
      Ans = max(Ans, i + p);
  }

  printf("%d
", Ans);

  return 0;
}
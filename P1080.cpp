#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

pair<long, long> p[1001];
long sum[2333], ans[2333], divn[2333];

void compare() {
  for (long k = max(ans[0], divn[0]); k; k--) {
    if (ans[k] > divn[k])
      return;
    if (ans[k] < divn[k]) {
      for (long j = 0; j <= divn[0]; j++)
        ans[j] = divn[j];
      return;
    }
  }
  return;
}

int main() {
  long n, x;
  cin >> n;
  for (long i = 0; i <= n; i++)
    cin >> p[i].first >> p[i].second;
  stable_sort(p + 1, p + n + 1, [](const pair<long, long> & x, const pair<long, long> & y) {
    return x.first * x.second < y.first * y.second;
  });
  sum[0] = sum[1] = 1;
  for (long i = 1; i <= n; i++) {
    x = 0;
    for (long j = 1; j <= sum[0]; j++) {
      sum[j] = sum[j] * p[i - 1].first + x;
      x = sum[j] / 10000;
      sum[j] %= 10000;
    }
    if (x > 0) {
      sum[++sum[0]] = x;
    }
    x = 0;
    memset(divn, 0, sizeof divn);
    for (long j = sum[0]; j > 0; j--) {
      divn[j] = (x * 10000 + sum[j]) / p[i].second;
      x = (x * 10000 + sum[j]) % p[i].second;
    }
    divn[0] = sum[0];
    while (!divn[divn[0]])
      divn[0]--;
    compare();
  }
  printf("%ld", ans[ans[0]]);
  for (long i = ans[0] - 1; i > 0; i--) {
    printf("%ld%ld%ld%ld", ans[i] / 1000, ans[i] / 100 % 10, ans[i] / 10 % 10, ans[i] % 10);
  }
  return 0;
}
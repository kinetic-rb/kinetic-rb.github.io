#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

pair<long, long> p[1001];
long sum[2333], ans[2333], divn[2333];

void compare() {
\tfor (long k = max(ans[0], divn[0]); k; k--) {
\t\tif (ans[k] > divn[k])
\t\t\treturn;
\t\tif (ans[k] < divn[k]) {
\t\t\tfor (long j = 0; j <= divn[0]; j++)
\t\t\t\tans[j] = divn[j];
\t\t\treturn;
\t\t}
\t}
\treturn;
}

int main() {
\tlong n, x;
\tcin >> n;
\tfor (long i = 0; i <= n; i++)
\t\tcin >> p[i].first >> p[i].second;
\tstable_sort(p + 1, p + n + 1, [](const pair<long, long> & x, const pair<long, long> & y) {
\t\treturn x.first * x.second < y.first * y.second;
\t});
\tsum[0] = sum[1] = 1;
\tfor (long i = 1; i <= n; i++) {
\t\tx = 0;
\t\tfor (long j = 1; j <= sum[0]; j++) {
\t\t\tsum[j] = sum[j] * p[i - 1].first + x;
\t\t\tx = sum[j] / 10000;
\t\t\tsum[j] %= 10000;
\t\t}
\t\tif (x > 0) {
\t\t\tsum[++sum[0]] = x;
\t\t}
\t\tx = 0;
\t\tmemset(divn, 0, sizeof divn);
\t\tfor (long j = sum[0]; j > 0; j--) {
\t\t\tdivn[j] = (x * 10000 + sum[j]) / p[i].second;
\t\t\tx = (x * 10000 + sum[j]) % p[i].second;
\t\t}
\t\tdivn[0] = sum[0];
\t\twhile (!divn[divn[0]])
\t\t\tdivn[0]--;
\t\tcompare();
\t}
\tprintf("%ld", ans[ans[0]]);
\tfor (long i = ans[0] - 1; i > 0; i--) {
\t\tprintf("%ld%ld%ld%ld", ans[i] / 1000, ans[i] / 100 % 10, ans[i] / 10 % 10, ans[i] % 10);
\t}
\treturn 0;
}
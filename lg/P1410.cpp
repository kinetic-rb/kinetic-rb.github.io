#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> mt;
hash<int> HT;
int b[2002];
int n, m;
bool cont;

inline void dfs(int q1len = 0,
                int q2len = 0,
                int q1end = 0,
                int q2end = 0,
                int idx = 1) {
  if (max(q1len, q2len) > m or cont or
      mt[HT(q1end * 100000 + q2len * 10000 + q1end * 1000 + q2end)])
    return;
  mt[HT(q1end * 100000 + q2len * 10000 + q1end * 1000 + q2end)] = true;
  if (idx > n) {
    cont = true;
    return;
  }
  if (b[idx] > b[q1end])
    dfs(q1len + 1, q2len, idx, q2end, idx + 1);
  if (b[idx] > b[q2end])
    dfs(q1len, q2len + 1, q1end, idx, idx + 1);
}

int main() {
  for (; cin >> n; cont = false) {
    *b = -1;
    for (int i = 1; i <= n; i++)
      cin >> b[i];
    m = n >> 1;
    dfs();
    puts(cont ? "Yes!" : "No!");
    mt.clear();
  }
  return 0;
}
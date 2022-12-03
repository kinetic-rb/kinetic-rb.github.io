#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <string>

using namespace std;
using tp = int32_t;
constexpr tp Hat_N = 153, Hat_Str_Len = 73, Hat_T_Len = 1e6 + 3;

string s[Hat_N];
tp fcnt[Hat_T_Len], ID[Hat_T_Len], fail[Hat_T_Len], son[Hat_T_Len][29];
tp root;

void Clear() {
  memset(son, 0, sizeof son);
  memset(fcnt, 0, sizeof fcnt);
  memset(fail, 0, sizeof fail);
}

void insert(string s, tp id) {
  tp now = root;
  for (tp i = 0; i < s.size(); ++i) {
    tp x = s[i] - 'a';
    if (!son[now][x]) {
      static tp tot = 0;
      son[now][x] = ++tot;
    }
    now = son[now][x];
  }
  ID[now] = id;
}

void Calc_Fail() {
  list<tp> q;
  for (tp i = 0; i < 26; ++i) {
    if (son[root][i]) {
      q.push_back(son[root][i]);
    }
  }
  while (q.size()) {
    for (tp i = 0; i < 26; ++i) {
      if (son[q.front()][i]) {
        fail[son[q.front()][i]] = son[fail[q.front()]][i];
        q.push_back(son[q.front()][i]);
      } else {
        son[q.front()][i] = son[fail[q.front()]][i];
      }
    }
    q.pop_front();
  }
}

signed main() {
  tp n;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n, n) {
    tp now = root, tar;
    string t;
    Clear();
    for (tp i = 1; i <= n; ++i) {
      cin >> s[i];
      insert(s[i], i);
    }
    Calc_Fail();
    cin >> t;
    for (auto&& i : t) {
      now = son[now][i - 'a'];
      for (tp j = now; j; j = fail[j]) {
        if (ID[j]) {
          ++fcnt[ID[j]];
        }
      }
    }
    tar = *max_element(fcnt + 1, fcnt + n + 1);
    cout << tar << '\n';
    for (tp i = 1; i <= n; ++i) {
      if (fcnt[i] == tar) {
        cout << s[i] << '\n';
      }
    }
  }
  return 0;
}
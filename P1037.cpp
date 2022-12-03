#include "cstdio"
#include "cstring"
#include "string"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int num[31], ans[35], s;
vector<int> map[10];
bool book[10];
long long sum = 1;
int len = 0;
char x;

inline void DFS(int cur) {
  int key = cur;
  for (int i = 0; i < map[key].size(); i++) {
    if (!book[map[key][i]]) {
      book[map[key][i]] = true;
      s++;
      DFS(map[key][i]);
    }
  }
}

int main() {
  int k, p = 0;
  while ((x = getchar()) && x != ' ') {
    num[len++] = x - '0';
  }
  cin >> k;
  int key, value;
  for (int i = 0; i < k; i++) {
    cin >> key >> value;
    map[key].push_back(value);
  }
  for (int i = 0; i < len; i++) {
    s = 1;
    book[num[i]] = true;
    DFS(num[i]);
    memset(book, false, 10);
    ans[i] = s;
  }
  vector<int> res;
  res.push_back(ans[0]);
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < res.size(); j++) {
      int t = ans[i] * res[j] + p;
      res[j] = t % 10;
      p = t / 10;
    }
    while (p) {
      res.push_back(p % 10);
      p /= 10;
    }
  }
  for (int i = res.size() - 1; i >= 0; i--)
    cout << res[i];
  return 0;
}
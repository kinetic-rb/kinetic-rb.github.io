#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

inline string calc(string x, string y) {
  string ans = "";
  int w = max(x.size(), y.size());
  if (x.size() < w) {
    string z = "";
    for (int i = 0; i < w - x.size(); i++)
      z.push_back(0);
    x = z + x;
  } else if (y.size() < w) {
    string z = "";
    for (int i = 0; i < w - y.size(); i++)
      z.push_back(0);
    y = z + y;
  }
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  for (int i = 0; i <= w; i++) {
    static int j = 0;
    int sum = x[i] + y[i] + j;
    ans.push_back(sum % 10);
    if (sum < 7)
      j = 0;
    else if (sum > 6 and sum < 14)
      j = 1;
    else
      j = 2;
  }
  if (!ans[w])
    ans.resize(w);
  reverse(ans.begin(), ans.end());
  for (auto& i : ans)
    i += 48;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  queue<string> et;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    et.push(x);
  }
  while (et.size() > 1) {
    string x = et.front(), y;
    et.pop();
    y = et.front();
    for (auto& i : x)
      i -= 48;
    for (auto& i : y)
      i -= 48;
    et.front() = calc(x, y);
  }
  cout << et.front();
  return 0;
}
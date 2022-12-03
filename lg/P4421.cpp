#include <bits/stdc++.h>

using namespace std;

const int N = 20005;

int n, r;
map<string, int> p;
string s[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    p[s[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    map<string, int> a;
    r += max(0, p[s[i]] - 1);
    for (int j = 0; j < s[i].size(); j++) {
      for (int k = 1; k < s[i].size(); k++) {
        if (p[s[i].substr(j, k)] && !a[s[i].substr(j, k)]++) {
          r += p[s[i].substr(j, k)];
        }
      }
    }
  }
  cout << r;
  return 0;
}
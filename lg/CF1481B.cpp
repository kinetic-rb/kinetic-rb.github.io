#include <cstring>
#include <iostream>

using namespace std;

int num[105];
int n, k;

inline void calc() {
  int j;
  for (int i = 1; i <= k; i++) {
    for (j = 1; num[j] >= num[j + 1] && j <= n; j++);
    if (j > n) {
    \tputs("-1");
    \treturn;
    } else
      num[j]++;
  }
  cout << j << '\n';
  return;
}

int main() {
\tint t;
\tfor (cin >> t; t--;){
\t  memset(num, 0, sizeof num);
\t  cin >> n >> k;
\t  for (int i = 1; i <= n; i++)
\t    cin >> num[i];
    calc();
  }
\treturn 0;
}
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
      puts("-1");
      return;
    } else
      num[j]++;
  }
  cout << j << '\n';
  return;
}

int main() {
  int t;
  for (cin >> t; t--;){
    memset(num, 0, sizeof num);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
      cin >> num[i];
    calc();
  }
  return 0;
}
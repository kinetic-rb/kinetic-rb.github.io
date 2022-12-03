#include <iostream>
#define int long long

using namespace std;

int to[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

inline int SUM(int x) {
  int sum;
  for (sum = to[x % 10]; x /= 10; sum += to[x % 10]);
  return sum;
}

signed main() {
  int n, cnt = 0;
  cin >> n;
  for (int A = 0; SUM(A) < n; A++) {
    for (int B = 0; SUM(A) + SUM(B) < n + 10; B++) {
      int C = A + B;
      if (n == SUM(C) + SUM(A) + SUM(B) + 4)
        cnt++;
    }
  }
  cout << cnt;
  return 0;
}
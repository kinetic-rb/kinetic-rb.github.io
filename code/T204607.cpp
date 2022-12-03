#include<bits/stdc++.h>
using namespace std;
int n, x, y, a, b, c[1005], sum = 0, ans = 0;
int main(){
  cin >> n >> x >> y >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  sort(c + 1, c + n + 1);
  for (ans = 1; ans * a < sum && ans <= x; ans++) {
  }
  for (int i = 1; i * b + ans * a < sum && i <= y; i++, ans++) {
  }
  if (x * a + y * b < sum) {
    int i, t = 0;
    for (i = 1; t + c[i] <= x * a + y * b; i++) {
      t += c[i];
    }
    cout << "Error" << endl << i - 1;
  } else {
    cout << ans;
  }
  return 0;
}


#include <iostream>

using namespace std;

int main() {
  long long a, b, ans;
  cin >> a >> b;
  ans = a;
  for (int i = 1; i < b; i++)
    ans = ans * a % 1000;
  printf("%03lld", ans);
  return 0;
}
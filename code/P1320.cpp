#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  string str = " ", tmp;
  while (cin >> tmp)
    str += tmp;
  n = sqrt(str.size() - 1);
  cout << n << " ";
  int cur = 0;
  char flag = '0';
  for (int i = 1; i <= n * n; i++) {
    if (str[i] == flag)
      cur++;
    else {
      cout << cur << " ";
      flag = str[i];
      cur = 1;
    }
  }
  cout << cur;
  return 0;
}
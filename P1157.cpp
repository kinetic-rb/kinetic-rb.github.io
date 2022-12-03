#include <iostream>
#include <iomanip>

using namespace std;

int n, m;
int cbp[22];

inline void combination(int x, int last) {
  if(x == m + 1) {
    for(int i = 1; i <= m; i++)
      cout << setw(3) << cbp[i];
    cout << '\n';
  }
  for(int i = last + 1; i <= n; i++) {
    cbp[x] = i;
    combination(x + 1, i);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin >> n >> m;
  combination(1, 0);
  return 0;
}
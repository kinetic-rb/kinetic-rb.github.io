#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int sum = 0, mark = 0, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    sum += m;
  }
  mark = sum;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    mark -= m;
  }
  cout << fixed << setprecision(6) << (sum * 1.0 / mark + 2);
  return 0;
}
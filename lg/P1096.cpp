#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  int n;
  cin >> n;
  stringstream s;
  s << fixed << setprecision(0) << pow(2.0l, n + 1);
  string a = s.str();
  a[a.size() - 1] -= 2;
  cout << a;
  return 0;
}
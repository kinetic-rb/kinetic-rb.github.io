#include <iostream>
using namespace std;
int main() {
  register int h, m, s;
  cin >> h >> m >> s;
  cout << h * 3600 + m * 60 + s;
}
#include <iostream>

using namespace std;

pair<int, int> p[5];
int c[3];
char ch;

int main() {
  for (int i = 1; i <= 4; i++) {
    cin >> ch >> p[i].first >> ch >> p[i].second >> ch;
  }
  p[0] = p[3];
  for (int i = 0; i <= 2; i++) {
    int v = (p[i + 1].first - p[i].first) * (p[4].second - p[i].second) - (p[4].first - p[i].first) * (p[i + 1].second - p[i].second);
    ++c[v ? (v < 0 ? 0 : 2) : 1];
  }
  if (c[1] == 2) {
    cout << 4;
  } else if (c[1] == 1 && (c[0] == 2 || !c[0])) {
    cout << 3;
  } else {
    cout << (c[0] == 3 || !c[0] ? 1 : 2);
  }
  return 0;
}
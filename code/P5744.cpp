#include <iostream>

using namespace std;

int main() {
  int n;
  for (cin >> n; n--; ) {
    string name;
    int y, mark;
    cin >> name >> y >> mark;
    cout << name << ' ' << ++y << ' ' << min(600, mark * 6 / 5) << '\n';
  }
  return 0;
}
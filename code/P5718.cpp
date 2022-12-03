#include <iostream>
#include <algorithm>

using namespace std;

int num[101];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  cout << *min_element(num, num + n);
  return 0;
}
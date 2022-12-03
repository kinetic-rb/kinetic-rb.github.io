#include <iostream>
#include <vector>

using namespace std;

int s[5005], t[5005];

int main() {
  vector<bool> ap(1000005);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < i; j++) {
      ap[abs(s[i] - s[j])] = true;
    }
  }
  while (ap[n++]);
  cout << --n;
  return 0;
}
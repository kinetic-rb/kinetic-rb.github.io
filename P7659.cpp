#include <iostream>

using namespace std;

int num[24];

int main() {
  int MAX = 0;
  for (int i = 0; i < 8; i++)
    cin >> num[i], num[i + 8] = num[i];
  for (int i = 0; i < 16; i++) {
    int sum = 0;
    for (int j = i; j < i + 4; j++)
      sum += num[j];
    MAX = max(MAX, sum);
  }
  cout << MAX;
  return 0;
} 
#include <array>
#include <iostream>
#define DEBUG 0

inline void FileSwitch(const char* InputFileName, const char* OutputFileName) {
#if DEBUG
  FILE* STREAM;
  freopen_s(&STREAM, InputFileName, "r", stdin);
#endif
#if DEBUG == 2
  freopen_s(&STREAM, OutputFileName, "w", stdout);
#endif
}

using namespace std;

array<int, 1001> num;

int main() {
  FileSwitch("^", "#");
  int n, t;
  cin >> n >> t;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  while (t--) {
    int MAX = 0, ptr = 1;
    for (int i = 1; i <= n; i++)
      if (num[i] > MAX) {
        MAX = num[i];
        ptr = i;
      }
    int val = num[ptr] / (n - 1);
    cout << ptr << '\n';
    for (int i = 1; i <= n; i++)
      if (i != ptr)
        num[i] += val;
    num[ptr] %= (n - 1);
    for (int i = 1; i <= n && num[ptr]; i++)
      if (i != ptr) {
        num[i]++;
        num[ptr]--;
      }
  }
  return 0;
}
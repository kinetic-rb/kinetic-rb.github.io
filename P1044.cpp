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

int f[] = {1,       1,       2,        5,         14,       42,     132,
           429,     1430,    4862,     16796,     58786,    208012, 742900,
           2674440, 9694845, 35357670, 129644790, 477638700};

int main() {
  FileSwitch("#1", "#");
  int n;
  cin >> n;
  cout << f[n];
  return 0;
}
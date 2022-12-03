#include <array>
#include <iostream>
#include <map>
#define DEBUG 0

using namespace std;

inline void FileSwitch(const char* InputFileName) {
#if DEBUG
  FILE* STREAM;
  freopen_s(&STREAM, InputFileName, "r", stdin);
#endif
}

int main() {
  FileSwitch("#1.in");
  map<array<int, 256>, bool> mp;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    array<int, 256> arr;
    arr.fill(0);
    string x;
    cin >> x;
    for (auto& i : x)
      arr[i]++;
    mp[arr] = true;
  }
  cout << mp.size();
  return 0;
}
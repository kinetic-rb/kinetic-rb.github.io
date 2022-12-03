#include <algorithm>
#include <iostream>
#define DEBUG 0

using namespace std;

inline void FileSwitch(const char* InputFileName) {
#if DEBUG
  FILE* STREAM;
  freopen_s(&STREAM, InputFileName, "r", stdin);
#endif
}

inline string t(const string& x) {
  bool I = true, O = true;
  for (auto& i : x)
    if (i == '1')
      O = false;
    else
      I = false;
  if (O)
    return "A";
  if (I)
    return "B";
  return 'C' + t(x.substr(0, x.size() >> 1)) +
         t(x.substr(x.size() >> 1, x.size()));
}

int main() {
  FileSwitch("#2.in");
  string s;
  cin >> s;
  cout << t(s);
  return 0;
}
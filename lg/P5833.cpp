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

int n, *ord = new int[8], *tx, *ty;
string Lit = "Z";

inline string to_name(const int& x) {
  switch (x) {
    case 1:
      return "Beatrice
";
    case 2:
      return "Sue
";
    case 3:
      return "Belinda
";
    case 4:
      return "Bessie
";
    case 5:
      return "Betsy
";
    case 6:
      return "Blue
";
    case 7:
      return "Bella
";
    default:
      return "Buttercup
";
  }
}

inline int to_id(const string& name) {
  if (name == "Beatrice")
    return 1;
  if (name == "Sue")
    return 2;
  if (name == "Belinda")
    return 3;
  if (name == "Bessie")
    return 4;
  if (name == "Betsy")
    return 5;
  if (name == "Blue")
    return 6;
  if (name == "Bella")
    return 7;
  return 8;
}

inline void calc() {
  for (int i = 0; i < n; i++) {
    int x, y;
    for (int j = 0; j < 8; j++)
      if (ord[j] == tx[i])
        x = j;
    for (int j = 0; j < 8; j++)
      if (ord[j] == ty[i])
        y = j;
    if (abs(x - y) != 1)
      return;
  }
  string temp = "";
  for (int i = 0; i < 8; i++)
    temp += to_name(ord[i]);
  Lit = min(Lit, temp);
}

int main() {
  FileSwitch("#1.in");
  cin >> n;
  tx = new int[n];
  ty = new int[n];
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    tx[i] = to_id(x);
    cin >> x >> x >> x >> x >> x;
    ty[i] = to_id(x);
  }
  for (int i = 0; i < 8; i++)
    ord[i] = i + 1;
  for (calc(); next_permutation(ord, ord + 8); calc())
    ;
  delete[] tx, ty, ord;
  cout << Lit;
  return 0;
}
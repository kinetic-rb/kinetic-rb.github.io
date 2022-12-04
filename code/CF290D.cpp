#include <iostream>
#include <string>

using namespace std;

signed main() {
  string x;
  int n;
  cin >> x >> n;
  for (auto&& i : x) {           // \u904d\u5386
    if (i >= 'A' && i <= 'Z') {  // \u5927\u5199
      i = i - 'A' + 'a';         // \u5927\u5199\u53d8\u5c0f\u5199
    }
  }
  for (auto&& i : x) {  // \u904d\u5386
    if (i - 'a' < n) {               // \u5982\u679c\u6ee1\u8db3\u9898\u76ee\u7684\u8981\u6c42
      i = i - 'a' + 'A';          // \u5c0f\u5199\u53d8\u5927\u5199
    }
  }
  cout << x;
  return 0;
}
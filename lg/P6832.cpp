#if false
#include <fstream>
std::ifstream cin("beta.in");
std::ofstream cout(stdout);
#else
#include <iostream>
#endif
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  auto* num = new int[256];
  memset(num, 0, 1024);
  string x;
  cin >> x;
  for (auto& i : x)
    num[i]++;
  cout << *max_element(num, num + 256);
  return 0;
}
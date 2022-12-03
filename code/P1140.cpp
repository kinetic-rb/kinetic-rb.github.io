#include <iostream>

using namespace std;

const char tab[5][5] = { 5, -1, -2, -1, -3, -1, 5, -3, -2, -4, -2, -3, 5, -2, -2, -1, -2, -2, 5, -1, -3, -4, -2, -1, 0 };
int f[105][105];
string s1, s2;

inline int to(const char& c) {
  enum {A = 0, C = 1, G = 2, T = 3};
  switch (c) {
    case 'A' : return A;
    case 'C' : return C;
    case 'G' : return G;
    case 'T' : return T;
  }
}

int main() {
  cin >> s1 >> s1 >> s2 >> s2;
  for (int i = 1; i <= s1.size(); i++)
    for (int j = 1; j <= s2.size(); j++)
      f[i][j] = -0x7fffffff;
  for (int i = 1; i <= s1.size(); i++)
    f[i][0] = f[i - 1][0] + tab[to(s1[i - 1])][4];
  for (int j = 1; j <= s2.size(); j++)
    f[0][j] = f[0][j - 1] + tab[4][to(s2[j - 1])];
  for (int i = 1; i <= s1.size(); i++)
    for (int j = 1; j <= s2.size(); j++) {
      f[i][j] = max(f[i][j], f[i - 1][j] + tab[to(s1[i - 1])][4]);
      f[i][j] = max(f[i][j], f[i][j - 1] + tab[4][to(s2[j - 1])]);
      f[i][j] = max(f[i][j], f[i - 1][j - 1] + tab[to(s1[i - 1])][to(s2[j - 1])]);
    }
  cout << f[s1.size()][s2.size()];
  return 0;
}
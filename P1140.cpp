#include <iostream>

using namespace std;

const char tab[5][5] = { 5, -1, -2, -1, -3, -1, 5, -3, -2, -4, -2, -3, 5, -2, -2, -1, -2, -2, 5, -1, -3, -4, -2, -1, 0 };
int f[105][105];
string s1, s2;

inline int to(const char& c) {
\tenum {A = 0, C = 1, G = 2, T = 3};
\tswitch (c) {
\t\tcase 'A' : return A;
\t\tcase 'C' : return C;
\t\tcase 'G' : return G;
\t\tcase 'T' : return T;
\t}
}

int main() {
\tcin >> s1 >> s1 >> s2 >> s2;
\tfor (int i = 1; i <= s1.size(); i++)
\t\tfor (int j = 1; j <= s2.size(); j++)
\t\t\tf[i][j] = -0x7fffffff;
\tfor (int i = 1; i <= s1.size(); i++)
\t\tf[i][0] = f[i - 1][0] + tab[to(s1[i - 1])][4];
\tfor (int j = 1; j <= s2.size(); j++)
\t\tf[0][j] = f[0][j - 1] + tab[4][to(s2[j - 1])];
\tfor (int i = 1; i <= s1.size(); i++)
\t\tfor (int j = 1; j <= s2.size(); j++) {
\t\t\tf[i][j] = max(f[i][j], f[i - 1][j] + tab[to(s1[i - 1])][4]);
\t\t\tf[i][j] = max(f[i][j], f[i][j - 1] + tab[4][to(s2[j - 1])]);
\t\t\tf[i][j] = max(f[i][j], f[i - 1][j - 1] + tab[to(s1[i - 1])][to(s2[j - 1])]);
\t\t}
\tcout << f[s1.size()][s2.size()];
\treturn 0;
}
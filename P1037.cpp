#include "cstdio"
#include "cstring"
#include "string"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int num[31], ans[35], s;
vector<int> map[10];
bool book[10];
long long sum = 1;
int len = 0;
char x;

inline void DFS(int cur) {
\tint key = cur;
\tfor (int i = 0; i < map[key].size(); i++) {
\t\tif (!book[map[key][i]]) {
\t\t\tbook[map[key][i]] = true;
\t\t\ts++;
\t\t\tDFS(map[key][i]);
\t\t}
\t}
}

int main() {
\tint k, p = 0;
\twhile ((x = getchar()) && x != ' ') {
\t\tnum[len++] = x - '0';
\t}
\tcin >> k;
\tint key, value;
\tfor (int i = 0; i < k; i++) {
\t\tcin >> key >> value;
\t\tmap[key].push_back(value);
\t}
\tfor (int i = 0; i < len; i++) {
\t\ts = 1;
\t\tbook[num[i]] = true;
\t\tDFS(num[i]);
\t\tmemset(book, false, 10);
\t\tans[i] = s;
\t}
\tvector<int> res;
\tres.push_back(ans[0]);
\tfor (int i = 1; i < len; i++) {
\t\tfor (int j = 0; j < res.size(); j++) {
\t\t\tint t = ans[i] * res[j] + p;
\t\t\tres[j] = t % 10;
\t\t\tp = t / 10;
\t\t}
\t\twhile (p) {
\t\t\tres.push_back(p % 10);
\t\t\tp /= 10;
\t\t}
\t}
\tfor (int i = res.size() - 1; i >= 0; i--)
\t\tcout << res[i];
\treturn 0;
}
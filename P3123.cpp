#include <iostream>
#define fr(name) for (tp name(0); name ^ 7; ++name)

using namespace std;
using tp = int_fast64_t;

enum { B, E, S, I, G, O, M };

tp h[7][7];

signed main() {
\ttp n, sum = 0;
\tcin >> n;
\twhile (n--) {
\t\tchar c;
\t\ttp x;
\t\tcin >> c >> x;
\t\tx %= 7;
\t\tif (x < 0) {
\t\t    x += 7;
\t\t}
\t\tif (c == 'B') {
\t\t\t++h[B][x];
\t\t}
\t\tif (c == 'E') {
\t\t\t++h[E][x];
\t\t}
\t\tif (c == 'S') {
\t\t\t++h[S][x];
\t\t}
\t\tif (c == 'I') {
\t\t\t++h[I][x];
\t\t}
\t\tif (c == 'G') {
\t\t\t++h[G][x];
\t\t}
\t\tif (c == 'O') {
\t\t\t++h[O][x];
\t\t}
\t\tif (c == 'M') {
\t\t\t++h[M][x];
\t\t}
\t}
\tfr(b) {
\t\tif (h[B][b]) {
\t\t\tfr(e) {
\t\t\t\tif (h[E][e]) {
\t\t\t\t\tfr(s) {
\t\t\t\t\t\tif (h[S][s]) {
\t\t\t\t\t\t\tfr(i) {
\t\t\t\t\t\t\t\tif (h[I][i]) {
\t\t\t\t\t\t\t\t\tfr(g) {
\t\t\t\t\t\t\t\t\t\tif (h[G][g]) {
\t\t\t\t\t\t\t\t\t\t\tfr(o) {
\t\t\t\t\t\t\t\t\t\t\t\tif (h[O][o]) {
\t\t\t\t\t\t\t\t\t\t\t\t\tfr (m) {
\t\t\t\t\t\t\t\t\t\t\t\t\t\tif (h[M][m]) {
\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tif (!((b + e + s + s + i + e) * (g + o + e + s) * (m + o + o) % 7)) {
\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tsum += h[B][b] * h[E][e] * h[S][s] * h[I][i] * h[G][g] * h[O][o] * h[M][m];
\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t}
\t\t\t\t\t\t}
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\t\t}
\t}
\tcout << sum;
\treturn 0;
}

/*
*/

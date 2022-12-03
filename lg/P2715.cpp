#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a, b;
char c, ch;

int main() {
\tc = getchar();
\twhile (c == ' ')
\t\tc = getchar();
\tif (c == '?') {
\t\tc = getchar();
\t\twhile (c == ' ')
\t\t\tc = getchar();
\t\tcin >> a >> ch >> b;
\t\tif (c == '+') {
\t\t\tprintf("%.2lf
", double(b) - double(a));
\t\t\treturn 0;
\t\t}
\t\tif (c == '-') {
\t\t\tprintf("%.2lf
", double(b) + double(a));
\t\t\treturn 0;
\t\t}
\t\tif (c == '*') {
\t\t\tprintf("%.2lf
", double(b) / double(a));
\t\t\treturn 0;
\t\t}
\t\tif (c == '/') {
\t\t\tprintf("%.2lf
", double(b) * double(a));
\t\t\treturn 0;
\t\t}
\t}
\telse {
\t\twhile (c >= '0' && c <= '9')
\t\t\ta = a * 10 + c - '0', c = getchar();
\t\twhile (c == ' ')
\t\t\tc = getchar();
\t\tch = c;
\t\tc = getchar();
\t\twhile (c == ' ')
\t\t\tc = getchar();
\t\tif (c == '?') {
\t\t\tcin >> c >> b;
\t\t\tif (ch == '+') {
\t\t\t\tprintf("%.2lf
", double(b) - double(a));
\t\t\t\treturn 0;
\t\t\t}
\t\t\tif (ch == '-') {
\t\t\t\tprintf("%.2lf
", double(a) - double(b));
\t\t\t\treturn 0;
\t\t\t}
\t\t\tif (ch == '*') {
\t\t\t\tprintf("%.2lf
", double(b) / double(a));
\t\t\t\treturn 0;
\t\t\t}
\t\t\tif (ch == '/') {
\t\t\t\tprintf("%.2lf
", double(a) / double(b));
\t\t\t\treturn 0;
\t\t\t}
\t\t}
\t\telse {
\t\t\twhile (c <= '9' && c >= '0')
\t\t\t\tb = b * 10 + c - '0', c = getchar();
\t\t\tif (ch == '+') {
\t\t\t\tprintf("%.2lf
", double(a) + double(b));
\t\t\t\treturn 0;
\t\t\t}
\t\t\tif (ch == '-') {
\t\t\t\tprintf("%.2lf
", double(a) - double(b));
\t\t\t\treturn 0;
\t\t\t}
\t\t\tif (ch == '*') {
\t\t\t\tprintf("%.2lf
", double(a) * double(b));
\t\t\t\treturn 0;
\t\t\t}
\t\t\tif (ch == '/') {
\t\t\t\tprintf("%.2lf
", double(a) / double(b));
\t\t\t\treturn 0;
\t\t\t}
\t\t}
\t}
\treturn 0;
}
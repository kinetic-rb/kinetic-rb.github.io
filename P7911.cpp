#include <iostream>

using namespace std;

bool HF(const string& x) {
\tif (x[0] == '.' || *(x.end() - 1) == ':')
\t\treturn false;
\tstring format;
\tint a, b, c, d, e, dc = 0, mc = 0;
\tfor (int i = 0; i < x.size(); i++)
\t\tif (x[i] == '.')
\t\t\tdc++;
\t\telse if (x[i] == ':')
\t\t\tmc++;
\tif (dc != 3 || mc != 1)
\t\treturn false;
\tfor (int i = 1; i < x.size() - 1; i++)
\t\tif (x[i] == '0' && x[i - 1] == '.' && (x[i + 1] != '.' && x[i + 1] != ':'))
\t\t\treturn false;
\tfor (int i = 1; i < x.size(); i++)
\t\tif (x[i] >= '0' && x[i] <= '9' && x[i - 1] == '0' && (i == 1 || x[i - 2] == '.' || x[i - 2] == ':'))
\t\t\treturn false;
\tif (x.find(".:") != string::npos || x.find("..") != string::npos || x.find(".", x.find(":")) != string::npos)
\t\treturn false;
\tsscanf(x.c_str(), "%d.%d.%d.%d:%d", &a, &b, &c, &d, &e);
\tif (min(a, min(b, min(c, d))) < 0 || max(a, max(b, max(c, d))) > 255 || e < 0 || e > 65535)
\t\treturn false;
\treturn true;
}

struct SERVER {
\tstring P;
\tint id;
} Server[1001];
int Server_cnt;

signed main() {
\tint n;
\tscanf("%d", &n);
\tfor (int k = 1; k <= n; k++) {
\t\tstring op, P;
\t\tcin >> op >> P;
\t\tif (!HF(P)) {
\t\t\tputs("ERR");
\t\t\tcontinue;
\t\t}
\t\tif (op == "Server") {
\t\t\tbool f = true;
\t\t\tfor (int j = 0; j < Server_cnt; j++)
\t\t\t\tif (Server[j].P == P) {
\t\t\t\t\tf = false;
\t\t\t\t\tputs("FAIL");
\t\t\t\t\tbreak;
\t\t\t\t}
\t\t\tif (f) {
\t\t\t\tServer[Server_cnt].P = P;
\t\t\t\tServer[Server_cnt++].id = k;
\t\t\t\tputs("OK");
\t\t\t}
\t\t} else {
\t\t\tint f = -1;
\t\t\tfor (int j = 0; j < Server_cnt; j++)
\t\t\t\tif (Server[j].P == P) {
\t\t\t\t\tf = Server[j].id;
\t\t\t\t\tbreak;
\t\t\t\t}
\t\t\tif (f != -1)
\t\t\t\tprintf("%d
", f);
\t\t\telse
\t\t\t\tputs("FAIL");
\t\t}
\t}
\treturn 0;
}

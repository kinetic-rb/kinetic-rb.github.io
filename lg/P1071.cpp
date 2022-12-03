#include <iostream>
#include <algorithm>

using namespace std;

int main() {
\tstring fi, to, sc, t1, t2, ans = "";
\tcin >> fi >> to >> sc;
\tif (sc == "HELLO") {
\t\tcout << "Failed";
\t\treturn 0;
\t}
\tt1 = fi;
\tt2 = to;
\tstable_sort(t1.begin(), t1.end());
\tt1.resize(unique(t1.begin(), t1.end()) - t1.begin());
\tstable_sort(t2.begin(), t2.end());
\tt2.resize(unique(t2.begin(), t2.end()) - t2.begin());
\tif (t1 != t2) {
\t\tcout << "Failed";
\t\treturn 0;
\t}
\tfor (auto i : sc) {
\t\tchar found = EOF;
\t\tfor (int j = 0; j < fi.size(); j++) {
\t\t\tif (i == fi[j]) {
\t\t\t\tfound = to[j];
\t\t\t}
\t\t}
\t\tif (found == EOF) {
\t\t\tcout << "Failed";
\t\t\treturn 0;
\t\t}
\t\tans.push_back(found);
\t}
\tif (ans == fi) {
\t\tcout << "Failed";
\t\treturn 0;
\t}
\tcout << ans;
\treturn 0;
}

/*
 ___       ___         ___________
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
\t\|____________|\t      \|___|  |___|
*/
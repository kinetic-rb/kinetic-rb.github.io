#include <bits/stdc++.h>

using namespace std;

const int LC = 1e9 + 7;

long long n, a[100000];

int main(){
\tcin >> n;
\ta[1] = 1;
\ta[2] = 1;
\tfor(int i = 3;i <= n;i++){
\t\ta[i] = (a[i - 1] + a[i - 2]) % LC;
\t}
\tcout << a[n] << endl;
\treturn 0;
}
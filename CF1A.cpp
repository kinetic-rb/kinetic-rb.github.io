#include <iostream>
#include <cmath>

using namespace std;

int main() {
\tlong long n, m, a;
\tcin >> n >> m >> a;
\tcout <<   (long long)(ceil(double(n) / double(a)) * ceil(double(m) / double(a)));
\treturn 0;
}
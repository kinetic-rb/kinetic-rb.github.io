#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
\tint x;
\tdouble a, b;
\tcin >> x;
\ta = x / 3.0 + 50;
\tb = x / 1.2;
\tif(a > b) {
\t    cout << "Walk";
\t    exit(0);
\t}
\tif(a<b) {
\t    cout << "Bike";
\t    exit(0);
\t}
\tcout << "All";
\texit(0);
}
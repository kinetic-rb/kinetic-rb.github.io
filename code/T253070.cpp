#include <iostream>
#include <cstdlib>

#define maximum(a, b, c) max(a, max(b, c))
#define minimum(a, b, c) min(a, min(b, c))
#define mid(a, b, c) a + b + c - maximum(a, b, c) - minimum(a, b, c)

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << minimum(a, b, c) << " " << mid(a, b, c) << " " << maximum(a, b, c);
    exit(0);
}
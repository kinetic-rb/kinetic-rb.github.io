#include <iostream>
#include <cstdlib>

#define maximum(a, b, c) max(a, max(b, c))
#define minimum(a, b, c) min(a, min(b, c))
#define mid(a, b, c) a + b + c - maximum(a, b, c) - minimum(a, b, c)

using namespace std;

int main() {
    char s;
    cin >> s;
    switch(s) {
        case 's' :
        case 'S' :
        case 'e' :
        case 'E' :
        case 'k' :
        case 'K' : cout << 1; exit(0);
        case 'l' :
        case 'L' :
        case 'u' :
        case 'U' :
        case 'n' :
        case 'N' :
        case 'a' :
        case 'A' : cout << -1; exit(0);
        default : cout << 0;
    }
    exit(0);
}
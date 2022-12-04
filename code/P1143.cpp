#include <iostream>

using namespace std;

inline int char_to_int(char a) {
    return '0' <= a && a <= '9' ? a - '0' : 10 + a - 'A';
}

inline char int_to_char(int a) {
    return a < 10 ? char('0' + a) : char(a - 10 + 'A');
}

int output[1 << 15];

int main() {
    int n, m, dec = 0, i, nu = 0;
    string inp;
    cin >> n >> inp >> m;
    for (i = 0; i < inp.size(); i++)
        dec = dec * n + char_to_int(inp[i]);
    while (dec)
        output[nu++] = dec % m, dec /= m;
    for (i = nu - 1; i > -1; i--)
        putchar(int_to_char(output[i]));
    return 0;
}
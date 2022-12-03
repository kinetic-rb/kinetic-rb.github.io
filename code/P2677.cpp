//O(2^n)
//O(n)
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <time.h>
#include <vector>
#include <climits>
#include <ctime>
#define il inline
#define R register

using namespace std;

namespace IO {
    const int str = 1 << 20;
    static char in_buf[str], *in_s, *in_t;
    bool __ = false;
    il char gc() {
        return (in_s == in_t) && (in_t = (in_s = in_buf) + fread(in_buf, 1, str, stdin)), in_s == in_t ? EOF : *in_s++;
    }
    il void in(string &ch) {
        ch.clear();
        if (__)
            return;
        register char c;
        while ((c = gc()) != EOF && isspace(c));
        if (c == EOF) {
            __ = true;
            return;
        }
        ch += c;
        while ((c = gc()) != EOF && !isspace(c)) ch += c;
        if (c == EOF)
            __ = true;
    }
    il void in(char &ch) {
        if (__)
            return;
        R char c;
        while ((c = gc()) != EOF && isspace(c));
        if (c == EOF)
            __ = true;
        else ch = c;
    }
    il void in(char *ch) {
        *ch = '\0';
        if (__)
            return;
        R char c;
        while ((c = gc()) != EOF && isspace(c));
        if (c == EOF) {
            __ = true;
            return;
        }
        *ch = c;
        ch++;
        while ((c = gc()) != EOF && !isspace(c))
            *ch = c, ch++;
        if (c == EOF)
            __ = true;
        *ch = '\0';
    }
    template<typename T>
    il void in(T &x) {
        if (__)
            return;
        R char c = gc();
        bool f = false;
        while (c != EOF && (c < '0' || c > '9'))
            f ^= (c == '-'), c = gc();
        if (c == EOF) {
            __ = true;
            return;
        }
        x = 0;
        while (c != EOF && '0' <= c && c <= '9')
            x = x * 10 + c - 48, c = gc();
        if (c == EOF)
            __ = true;
        if (f)
            x = -x;
    }
    template<typename T, typename ... arr>
    il void in(T &x, arr &... y) {
        in(x), in(y...);
    }
    const char ln = '\n';
    static char out_buf[str], *out_s = out_buf, *out_t = out_buf + str;
    il void flush() {
        fwrite(out_buf, 1, out_s - out_buf, stdout);
        out_s = out_buf;
    }
    il void pt(char c) {
        (out_s == out_t) ? (fwrite(out_s = out_buf, 1, str, stdout), *out_s++ = c) : (*out_s++ = c);
    }
    il void out(const char *s) {
        while (*s)
            pt(*s++);
    }
    il void out(char *s) {
        while (*s)
            pt(*s++);
    }
    il void out(char c) {
        pt(c);
    }
    il void out(string s) {
        for (R int i = 0; s[i]; i++)
            pt(s[i]);
    }
    template<typename T>
    il void out(T x) {
        if (!x) {
            pt('0');
            return;
        }
        if (x < 0)
            pt('-'), x = -x;
        char a[50], t = 0;
        while (x)
            a[t++] = x % 10, x /= 10;
        while (t--)
            pt(a[t] + '0');
    }
    template<typename T, typename ... arr>
    il void out(T x, arr &... y) {
        out(x), out(y...);
    }
}
using namespace IO;

int N, S, B, ans = INT_MAX;
int a[21];

//x\u8868\u793a\u8003\u8651\u662f\u5426\u9009\u62e9\u7b2cx\u4e2a\u6570\u5b57\uff0csum\u8868\u793a\u5976\u725b\u53e0\u51fa\u6765\u7684\u9ad8\u5ea6
inline void solve(int x, int sum){
    //\u679a\u4e3e\u5230\u4e00\u4e2a\u5b50\u96c6\u4e86
    if(x == N){
        //\u5982\u679c\u8eab\u9ad8\u548c\u5927\u4e8e\u7b49\u4e8e\u4e66\u67b6\u9ad8\u5ea6
        if(sum >= B) {
            //\u7ef4\u62a4\u7b54\u6848
            ans = min(ans, sum - B);
        }
        return;
    }
    solve(x + 1, sum); //\u4e0d\u9009a[x]
    solve(x + 1, sum + a[x]); //\u9009a[x]
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    in(N, B);
    //cin >> N >> B;
    for(register int i = 0; i < N; i++) {
        //cin >> a[i];
        in(a[i]);
    }
    solve(0, 0);
    cout << ans;
    return 0;
}
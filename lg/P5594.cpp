#include <iostream>
#include <string>
#include <cstdarg>
#include <algorithm>
#include <stdio.h>
#include <array>
#include <cstring>

inline auto _(int & _) {
    char ch = getchar();
    bool bol = false;
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    if(bol)
        _ = -_;
    return _;
}
inline auto _(bool & _) {
    char ch = getchar();
    while('0' > ch || ch > '9')
        ch = getchar();
    _ = (ch != '0');
    return _;
}
inline auto _(char & _) {
    return _ = getchar();
}
inline auto _(long & _) {
    char ch = getchar();
    bool bol = false;
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    if(bol)
        _ = -_;
    return _;
}
inline auto _(short & _) {
    char ch = getchar();
    bool bol = false;
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    if(bol)
        _ = -_;
    return _;
}
inline auto _(float & _) {
    char ch = getchar();
    bool bol = false;
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar()) {
        _ = _ * 10 + ch - 48;
    }
    if(ch == '.') {
        ch = getchar();
        for(unsigned int cnt = 1; '0' <= ch && ch <= '9'; ch = getchar()) {
            cnt *= 10;
            _ += (ch - 48) * 1.0 / cnt;
        }
    }
    if(bol) {
        _ = -_;
    }
    return _;
}
inline auto _(double & _) {
    char ch = getchar();
    bool bol = false;
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar()) {
        _ = _ * 10 + ch - 48;
    }
    if(ch == '.') {
        ch = getchar();
        for(unsigned int cnt = 1; '0' <= ch && ch <= '9'; ch = getchar()) {
            cnt *= 10;
            _ += (ch - 48) * 1.0 / cnt;
        }
    }
    if(bol) {
        _ = -_;
    }
    return _;
}
inline auto _(long long & _) {
    char ch = getchar();
    bool bol = false;
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    if(bol)
        _ = -_;
    return _;
}
inline auto _(long double & _) {
    char ch = getchar();
    bool bol = false;
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar()) {
        _ = _ * 10 + ch - 48;
    }
    if(ch == '.') {
        ch = getchar();
        for(unsigned int cnt = 1; '0' <= ch && ch <= '9'; ch = getchar()) {
            cnt *= 10;
            _ += (ch - 48) * 1.0 / cnt;
        }
    }
    if(bol) {
        _ = -_;
    }
    return _;
}
inline auto _(std::string & _) {
    std::getline(std::cin, _);
    return _;
}
inline auto _(unsigned int & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline auto _(unsigned char & _) {
    return _ = getchar();
}
inline auto _(unsigned long & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline auto _(unsigned short & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline auto _(unsigned long long & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
template <typename _element_1_, typename ... _element_2_>
inline _element_1_ _(_element_1_ & x, _element_2_ & ... y) {
    _(x);
    _(y ...);
}
inline void _(const char * format, ...) {
    va_list arg;
    va_start(arg, format);
    vfprintf(stdout, format, arg);
    va_end(arg);
}

using namespace std;

short a[1001][1001];
array <short, 1001> ans;
bool used[1001][1001];

int main() {
    register short n, m, k;
    _(n, m, k);
    for(register short i = 1; i <= n; i++) {
        for(register short j = 1; j <= m; j++)
            _(a[i][j]);
    }
    for(register short i = 1; i <= n; i++) {
        for(register short j = 1; j <= m; j++) {
            if(!used[a[i][j]][j]) {
                used[a[i][j]][j] = true;
                ans[a[i][j]]++;
            }
        }
    }
    for(register short i = 1; i <= k; i++)
        _("%d ", ans[i]);
    return 0;
}
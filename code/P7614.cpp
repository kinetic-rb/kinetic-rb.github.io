#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>

inline auto _(int & _) {
    char ch = getchar();
    bool bol = false;
    while(ch == ' ' || ch == '\n' || ch == '	')
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
    while(ch == ' ' || ch == '\n' || ch == '	')
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
    while(ch == ' ' || ch == '\n' || ch == '	')
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
    while(ch == ' ' || ch == '\n' || ch == '	')
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
    while(ch == ' ' || ch == '\n' || ch == '	')
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
    while(ch == ' ' || ch == '\n' || ch == '	')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline auto _(unsigned short & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '	')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline auto _(unsigned long long & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '	')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
template <typename _element_1, typename ... _element_2>
inline _element_1 _(_element_1 & x, _element_2 & ... y) {
    _(x);
    _(y ...);
}

struct AC {
    int val, id;
} x[8];

int main() {
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        _(x[i].val);
        x[i].id = i;
    }
    std::sort(x, x + 8, [](const AC & i, const AC & j) {
        return i.val > j.val;
    });
    std::sort(x, x + 5, [](const AC & i, const AC & j) {
        return i.id < j.id;
    });
    for(int i = 0; i < 5; i++) {
        sum += x[i].val;
    }
    std::cout << sum << '\n';
    for(int i = 0; i < 5; i++) {
        std::cout << ++x[i].id << ' ';
    }
    return 0;
}
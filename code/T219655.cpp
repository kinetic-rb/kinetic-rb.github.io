#include <iostream>
#include <algorithm>

inline int _(int & _) {
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
inline bool _(bool & _) {
    char ch = getchar();
    while('0' > ch || ch > '9')
        ch = getchar();
    _ = (ch != '0');
    return _;
}
inline char _(char & _) {
    return _ = getchar();
}
inline long _(long & _) {
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
inline short _(short & _) {
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
inline float _(float & _) {
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
        for(register unsigned int cnt = 1; '0' <= ch && ch <= '9'; ch = getchar()) {
            cnt *= 10;
            _ += (ch - 48) * 1.0 / cnt;
        }
    }
    if(bol) {
        _ = -_;
    }
    return _;
}
inline double _(double & _) {
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
        for(register unsigned int cnt = 1; '0' <= ch && ch <= '9'; ch = getchar()) {
            cnt *= 10;
            _ += (ch - 48) * 1.0 / cnt;
        }
    }
    if(bol) {
        _ = -_;
    }
    return _;
}
inline long long _(long long & _) {
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
inline long double _(long double & _) {
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
        for(register unsigned int cnt = 1; '0' <= ch && ch <= '9'; ch = getchar()) {
            cnt *= 10;
            _ += (ch - 48) * 1.0 / cnt;
        }
    }
    if(bol) {
        _ = -_;
    }
    return _;
}
inline std::string _(std::string & _) {
    std::getline(std::cin, _);
    return _;
}
inline unsigned int _(unsigned int & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '	')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline unsigned char _(unsigned char & _) {
    return _ = getchar();
}
inline unsigned long _(unsigned long & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '	')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline unsigned short _(unsigned short & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '	')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
inline unsigned long long _(unsigned long long & _) {
    char ch = getchar();
    while(ch == ' ' || ch == '\n' || ch == '	')
        ch = getchar();
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    return _;
}
template <typename _1, typename ... _2>
inline _1 _(_1 & x, _2 & ... y) {
    _(x);
    _(y ...);
}

using namespace std;

struct AC {
    int * mark = new int [2000];
    int id;
} ac[20000];

int main() {
    int n, m;
    _(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            _(ac[i].mark[j]);
        ac[i].id = i;
    }
    for(int i = 0; i < m; i++) {
        sort(ac, ac + n, [i](const AC & x, const AC & y) {
            return x.mark[i] > y.mark[i];
        });
        for(int j = 0; j < n; j++)
            cout << ac[j].id + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
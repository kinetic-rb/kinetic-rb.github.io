#include <iostream>
#include <stdio.h>
#include <cstring>
#include <array>

using namespace std;

class basic_IO_with_none_buf {
public:
    const char space = ' ', endl = '\n';
    inline int operator >> (int & _) const {
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
    inline bool operator >> (bool & _) const {
        char ch = getchar();
        while('0' > ch || ch > '9')
            ch = getchar();
        _ = (ch != '0');
        return _;
    }
    inline char operator >> (char & _) const {
        return _ = getchar();
    }
    inline long operator >> (long & _) const {
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
    inline short operator >> (short & _) const {
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
    inline float operator >> (float & _) const {
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
    inline double operator >> (double & _) const {
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
    inline long long operator >> (long long & _) const {
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
    inline long double operator >> (long double & _) const {
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
    inline std::string * operator >> (std::string & _) const {
        std::getline(std::cin, _);
        return & _;
    }
    inline unsigned int operator >> (unsigned int & _) const {
        char ch = getchar();
        while(ch == ' ' || ch == '\n' || ch == '\t')
            ch = getchar();
        for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
            _ = _ * 10 + ch - 48;
        return _;
    }
    inline unsigned char operator >> (unsigned char & _) const {
        return _ = getchar();
    }
    inline unsigned long operator >> (unsigned long & _) const {
        char ch = getchar();
        while(ch == ' ' || ch == '\n' || ch == '\t')
            ch = getchar();
        for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
            _ = _ * 10 + ch - 48;
        return _;
    }
    inline unsigned short operator >> (unsigned short & _) const {
        char ch = getchar();
        while(ch == ' ' || ch == '\n' || ch == '\t')
            ch = getchar();
        for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
            _ = _ * 10 + ch - 48;
        return _;
    }
    inline unsigned long long operator >> (unsigned long long & _) const {
        char ch = getchar();
        while(ch == ' ' || ch == '\n' || ch == '\t')
            ch = getchar();
        for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
            _ = _ * 10 + ch - 48;
        return _;
    }
    inline void operator << (const int & x) const {
        printf("%d", x);
    }
    inline void operator << (const bool & x) const {
        x ? printf("1") : printf("0");
    }
    inline void operator << (const char & x) const {
        putchar(x);
    }
    inline void operator << (const long & x) const {
        printf("%ld", x);
    }
    inline void operator << (const short & x) const {
        printf("%d", x);
    }
    inline void operator << (const float & x) const {
        printf("%f", x);
    }
    inline void operator << (const double & x) const {
        printf("%f", x);
    }
    inline void operator << (const long long & x) const {
        printf("%lld", x);
    }
    inline void operator << (const long double & x) const {
        printf("%Lf", x);
    }
    inline void operator << (const std::string & x) const {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cout << x;
    }
    inline void operator << (const unsigned int & x) const {
        printf("%ud", x);
    }
    inline void operator << (const unsigned char & x) const {
        putchar(x);
    }
    inline void operator << (const unsigned long & x) const {
        printf("%lu", x);
    }
    inline void operator << (const unsigned short & x) const {
        printf("%ud", x);
    }
    inline void operator << (const unsigned long long & x) const {
        printf("%llu", x);
    };
} bin;

int step[200000];
int k, n;

inline void nth_step(int nth) {
    /*
    for(int i = nth - 1; i >= max(0, nth - k); i--) {
        step[nth] += step[i];
        step[nth] %= 100003;
    }
     */
    for (int i = nth + 1; i <= nth + k; i++){
        step[i] += step[nth];
        step[i] %= 100003;
    }
}

int S(int n){
    if (n <= 0){
        return n == 0;
    }
    if (step[n] != -1){
        return step[n];
    }
    int ans = 0;
    for (int i = n - k; i <= n - 1; i++){
        ans += S(i);
        ans %= 100003;
    }
    return step[n] = ans;
}

int main() {
    step[0] = 1;
    bin >> n;
    bin >> k;
    /*
    for(int i = 0; i <= n; i++) {
        nth_step(i);
    }*/
    memset(step, -1, sizeof(step));
    bin << S(n);
    return 0;
}
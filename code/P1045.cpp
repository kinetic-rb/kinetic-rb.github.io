#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct Bignum {
    long long Num[110], Len;
    Bignum() {
        memset(Num, 0, sizeof Num);
        Len = 1;
    }
    inline void output() {
        for (int i = 100; i > 0; i--) {
            if (!(i % 10))
                putchar('\n');
            printf("%05d", Num[i - 1]);
        }
    }
    inline void operator <<= (const long long& x) {
        long long y = x;
        while (y) {
            long long Tmp = (y < 40) ? y : 40;
            for (int i = 0; i < Len; i++)
                Num[i] <<= Tmp;
            for (int i = 0; i < Len; i++)
                Num[i + 1] += Num[i] / 100000, Num[i] %= 100000;
            while (Num[Len] && Len < 100) {
                Num[Len + 1] += Num[Len] / 100000;
                Num[Len] %= 100000;
                Len++;
            }
            Num[100] = 0;
            y -= Tmp;
        }
    }
} Ans;

int main() {
    Ans.Num[0] = 1;
    int N;
    cin >> N;
    printf("%.f", log10(2) * N + 0.5);
    Ans <<= N;
    Ans.Num[0]--;
    Ans.output();
    return 0;
}
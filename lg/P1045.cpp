#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define f(a, b, c) for (int a = b; a <= c; a++)
#define g(a, b, c) for (int a = b; a >= c; a--)

const int Lim = 100000;

struct Bignum {
    long long Num[110], Len;
    Bignum() {
        memset(Num, 0, sizeof Num);
        Len = 1;
    }
    inline void output() {
        g(i, 100, 1) {
            if (i % 10 == 0)
                putchar('\n');
            printf("%05d", Num[i-1]);
        }
    }
    void operator <<= (const long long &x){
        long long y = x;
        while (y) {
            long long Tmp = (y < 40) ? y : 40;
            f(i, 0, Len - 1)
                Num[i] <<= Tmp;
            f(i, 0, Len - 1)
                Num[i + 1] += Num[i] / Lim, Num[i] %= Lim;
            while (Num[Len] && Len < 100) {
                Num[Len + 1] += Num[Len] / Lim;
                Num[Len] %= Lim;
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
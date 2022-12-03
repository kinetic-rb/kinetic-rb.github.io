#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
int n,sum;

inline bool IP(int m) {
    int i = 2;
    if (m < 2)
        return false;
    while (i <= sqrt(m) && m % i != 0)
        i++;
    return i > sqrt(m);
}

inline int hn(int m) {
    int s = 0;
    while (m > 0) {
        s = s * 10 + m % 10;
        m /= 10;
    }
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 11; i <= n; i++)
        if (IP(i) && hn(i) == i)
            sum++;
    printf("%d", sum);
}
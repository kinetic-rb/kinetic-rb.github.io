#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    register long n, num[20], ans, test = 1;
    while (scanf("%ld", &n) != -1) {
        ans = 0;
        for (register long i = 0; i < n; i++)
            scanf("%ld", &num[i]);
        for (register long i = 0; i < n; i++)
            for (register long s = 1, j = i; j < n; j++) {
                s *= num[j];
                ans = max(s, ans);
            }
        printf("Case #%ld: The maximum product is %lld.

", test, ans);
        test++;
    }
    exit(0);
}
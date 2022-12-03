#include <cstdio>
using namespace std;

double p[17] = {0, 28.9, 32.7, 45.6, 78.0, 35.0, 86.2, 27.8, 43.0, 56.0, 65.0};

int main() 
{
    int a[17]; 
    double ans = 0;
    for(int i = 1; i <= 10; ++i) 
        scanf("%d", &a[i]), ans += a[i] * p[i];
    printf("%.1lf", ans);
    return 0;
}
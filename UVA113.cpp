#include<math.h>
#include<stdio.h>

int main() {
    double x, y, ans;
    while(~scanf("%lf%lf",&x,&y))
        printf("%.0lf
",pow(y,1.0/x));
    return 0;
}
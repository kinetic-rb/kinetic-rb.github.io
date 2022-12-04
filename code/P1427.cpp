#include <stdio.h>

int main() {
    register int * ac = new int [99], cnt;
    for(; scanf("%d", & ac[cnt]), ac[cnt]; cnt++);
    for(; cnt--; printf("%d ", ac[cnt]));
    return 0;
}
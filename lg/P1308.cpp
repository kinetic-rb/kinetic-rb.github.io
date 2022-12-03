#include <stdio.h>
#include <string.h>
#include <math.h>

char len[101], b[1000001];

int main() {
    gets(len);
    gets(b);
    register int i, j, x = strlen(len), y = strlen(b), a, s = 0;
    a = y;
    for(i = 0; i < y; i++) {
        if((abs(b[i] - len[0]) == 32 || b[i] == len[0]) && (b[i - 1] < 'A' || b[i - 1] > 'z')) {
            for(j = 1; j < x; j++) {
                if(abs(b[i + j] - len[j]) != 32 && (b[i + j] != len[j]))
                    break;
            }
            if(j == x && (b[i + x] < 'A' || b[i + x] > 'z')) {
                s++;
                if (i < a)
                    a = i;
            }
        }
    }
    (s > 0) ? printf("%d %d", s, a) : printf("-1");
    return 0;
}
#include <stdio.h>

void dfs(int);
char max_element(char* first, char* last);

char choose[11] = {'a'};
int n;

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}

inline void dfs(int idx) {
    if (idx == n) {
        puts(choose);
        return;
    }
    for (int i = 'a'; i <= max_element(choose, choose + idx) + 1; i++) {
        choose[idx] = i;
        dfs(idx + 1);
    }
}


inline char max_element(char* first, char* last) {
    char max = 'a';
    while (first < last) {
        if (*first > max)
            max = *first;
        first++;
    }
    return max;
}
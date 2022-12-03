#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int main() {
    char s[256], temp;
    int i;
    gets(s);
    for (i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            temp = s[i];
            temp += 3;
            if (temp > 122)
                temp -= 26;
            temp -= 32;
            s[i] = temp;

        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            temp = s[i];
            temp += 3;
            if (temp > 90)
                temp -= 26;
            temp += 32;
            s[i] = temp;
        }
    }
    for (int i = strlen(s) - 1; i > -1; i--)
        cout << s[i];
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    char s[256];
    gets(s);
    for (int i = 0; s[i]; i++)
        switch (s[i]) {
            case 'T' :
                cout << "A";
                break;
            case 'A' :
                cout << "T";
                break;
            case 'C' :
                cout << "G";
                break;
            case 'G' :
                cout << "C";
        }
    return 0;
}
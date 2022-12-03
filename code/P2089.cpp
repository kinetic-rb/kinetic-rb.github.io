#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    if (n > 30 || n < 10) {
        cout << 0;
        return 0;
    }
    for (int a = 1; a < 4; a++)
        for (int b = 1; b < 4; b++)
            for (int c = 1; c < 4; c++)
                for (int d = 1; d < 4; d++)
                    for (int e = 1; e < 4; e++)
                        for (int f = 1; f < 4; f++)
                            for (int g = 1; g < 4; g++)
                                for (int h = 1; h < 4; h++)
                                    for (int i = 1; i < 4; i++) {
                                        int j = n - a - b - c - d - e - f - g - h - i;
                                        if (j > 0 && j < 4)
                                            cnt++;
                                    }
    printf("%d
", cnt);
    for (int a = 1; a < 4; a++)
        for (int b = 1; b < 4; b++)
            for (int c = 1; c < 4; c++)
                for (int d = 1; d < 4; d++)
                    for (int e = 1; e < 4; e++)
                        for (int f = 1; f < 4; f++)
                            for (int g = 1; g < 4; g++)
                                for (int h = 1; h < 4; h++)
                                    for (int i = 1; i < 4; i++) {
                                        int j = n - a - b - c - d - e - f - g - h - i;
                                        if (j > 0 && j < 4)
                                            printf("%d %d %d %d %d %d %d %d %d %d
", a, b, c, d, e, f, g, h, i, j);
                                    }
    return 0;
}
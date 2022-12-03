#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool t[10];
    int x = 100, y = 100, z = 100, tx, ty, tz;
    int s[9];
    for(; x < 1000; x++)
        for(y = 100; y < 1000; y++)
            for(z = 100; z < 1000; z++)
            {
                tx = x * 6;
                ty = y * 3;
                tz = z * 2;
                if(tx == ty)
                    if(ty == tz)
                        if(tx == ty)
                            if(ty == tz)
                            {
                                memset(t, false, sizeof(t));
                                t[x % 10 - 1] = true;
                                t[x / 10 % 10 - 1] = true;
                                t[x / 100 - 1] = true;
                                t[y % 10 - 1] = true;
                                t[y / 10 % 10 - 1] = true;
                                t[y / 100 - 1] = true;
                                t[z % 10 - 1] = true;
                                t[z / 10 % 10 - 1] = true;
                                t[z /100 - 1] = true;
                                if(t[0] && t[1] && t[2] && t[3] && t[4] && t[5] && t[6] && t[7] && t[8])
                                    cout << x << " " << y << " " << z << endl;
                            }
            }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
int main()
{
    bool e = true;
    int n;
    int pe[15], per[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pe[i];
    for(int i = 0; i < n; i++)
    {
        if(pe[i] != ++i)
            e = false;
    }
    if(e)
    {
        cout << 1;
        return 0;
    }
    for(int i = 0; next_permutation(per, per + n); i++)
    {
        bool e = true;
        for(int i = 0; i < n; i++)
            if(pe[i] != per[i])
                e = false;
        if(e)
        {
            cout << i + 2;
            return 0;
        }
    }
    return 0;
}
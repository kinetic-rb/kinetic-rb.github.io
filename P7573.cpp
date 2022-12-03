#include <iostream>
using namespace std;

int main()
{
   int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int p;
        cin >> p;
        if (p == 1) cout << 0 << endl;
        else cout << (p + 1) / 2 << endl;
    }
    return 0;
}
#include <iostream>

using namespace std;

int Ackmann(int m,int n)
{
    if(!m)
        return n + 1;
    if(m > 0 && !n)
        return Ackmann(m - 1, 1);
    return Ackmann(m - 1, Ackmann(m, n - 1));
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << Ackmann(m, n);
    return 0;
}
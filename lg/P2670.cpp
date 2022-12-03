#include <iostream>

using namespace std;

char c[1001][1001];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int sum = 0;
            if(c[i][j] == '*')
                cout << "*";
                    else
                    {
                        if(c[i - 1][j + 1] == '*')
                            sum++;
                        if(c[i][j + 1] == '*')
                            sum++;
                        if(c[i + 1][j + 1] == '*')
                            sum++;
                        if(c[i - 1][j] == '*')
                            sum++;
                        if(c[i + 1][j] == '*')
                            sum++;
                        if(c[i - 1][j - 1] == '*')
                            sum++;
                        if(c[i][j - 1] == '*')
                            sum++;
                        if(c[i + 1][j - 1] == '*')
                            sum++;
                        cout << sum;
                    }
        }
        cout << endl;
    }
    return 0;
}
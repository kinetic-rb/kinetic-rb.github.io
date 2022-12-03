#include <stdio.h>

#define int long long

class matrix
{
    public:
    int a,b;
    int c,d;
};

matrix multi(matrix x,matrix y)
{ // 2*2 \u77e9\u9635\u4e58\u6cd5
    int newa = (x.a*y.a+x.b*y.c) % 1000000007,newb = (x.a*y.b+x.b*y.d) % 1000000007 , newc = (x.c*y.a+x.d*y.c) % 1000000007, newd = (x.c*y.b+x.d*y.d) % 1000000007;
    return { newa,newb,newc,newd };
}

class Solution
{
    public:
    int fibonacci(int n)
    {
        if(!n)
            return 0;
        matrix ans = {1,0,0,1}; // \u5355\u4f4d\u9635
        while(n)
        {
        static matrix m = {1,1,1,0};
            if(n&1)
                ans = multi(ans,m);
            m = multi(m,m);
            n >>= 1;
        }
        return ans.b;
    }
};
signed main()
{
    Solution s;
    signed n;
    scanf("%d", &n);
    printf("%d", s.fibonacci(n+ 1) % 1000000007);
    return 0;
}
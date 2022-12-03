//\u6587\u4ef6\u5934//
#include<bits/stdc++.h>
using namespace std;

//\u51fd\u6570\u6846\u67b6//
bool judge(int x);
int calculate(int x,char z,int y);
int calculate1(int x);
bool judge1(float x,int y);

//\u5168\u5c40\u53d8\u91cf//
char s[100001];
//\u7a0b\u5e8f\u90e8\u5206//
/*


//1000//
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a+b;
    return 0;
}

//1001//
int main()
{
    printf("Hello,World!");
    return 0;
}

//1002//
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<b;
    return 0;
}

//1003//
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    printf("%8d %8d %8d",a,b,c);
    return 0;
}

//1004//
int main()
{
    char v;
    cin>>v;
    cout<<"	"<<v<<endl<<" "<<v<<v<<v<<endl<<v<<v<<v<<v<<v;
    return 0;
}

//1005//
int main()
{
    int a,x,b,y;
    cin>>x>>a>>y>>b;
    cout<<fixed<<setprecision(2)<<(b*y-a*x)*1.0/(b-a);
    return 0;
}

//1006//
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a+b;
    return 0;
}

//1007//
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a+b)*c;
    return 0;
}

//1008//
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a+b)*1.0/c;
    return 0;
}

//1009//
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a/b<<" "<<a%b;
}

//1010//
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<fixed<<setprecision(9)<<a*1.0/b;
    return 0;
}

//1011//
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<fixed<<setprecision(3)<<b*100.0/a<<"%";
    return 0;
}

//1012//
int main()
{
    double x,a,b,c,d,num;
    cin>>x>>a>>b>>c>>d;
    num=a*x*x*x+b*x*x+c*x+d;
    cout<<fixed<<setprecision(7)<<num;
    return 0;
}

//1013//
int main()
{
    double f;
    cin>>f;
    cout<<fixed<<setprecision(4)<<5*(f-32)/9;
    return 0;
}

//1014//
int main()
{
    double r;
    cin>>r;
    cout<<fixed<<setprecision(4)<<r*2<<" ";
    cout<<fixed<<setprecision(4)<<2*3.14159*r<<" ";
    cout<<fixed<<setprecision(4)<<3.14159*r*r;
    return 0;
}

//1015//
int main()
{
    double r1,r2;
    cin>>r1>>r2;
    cout<<fixed<<setprecision(2)<<1.0/((1/r1)+(1/r2));
    return 0;
}

//1016//
int main()
{
    int a;
    short b;
    cout<<sizeof(a)<<" "<<sizeof(b);
    return 0;
}

//1017//
int main()
{
    float a;
    double b;
    cout<<sizeof(a)<<" "<<sizeof(b);
    return 0;
}

//1018//
int main()
{
    bool a;
    char b;
    cout<<sizeof(a)<<" "<<sizeof(b);
    return 0;
}

//1019//
int main()
{
    float a;
    cin>>a;
    cout<<int(a);
    return 0;
}

//1020//
int main()
{
    char v;
    cin>>v;
    cout<<int(v);
    return 0;
}

//1021//
int main()
{
    int v;
    cin>>v;
    cout<<char(v);
    return 0;
}

//1022//
int main()
{
    int v;
    bool V;
    cin>>v;
    V=v;
    v=V;
    cout<<v;
}

//1023//
int main()
{
    cout<<sizeof("Hello, World!");
    return 0;
}

//1024//
int main()
{
    float v;
    cin>>v;
    cout<<fixed<<setprecision(3)<<v;
    return 0;
}

//1025//
int main()
{
    double v;
    cin>>v;
    cout<<fixed<<setprecision(12)<<v;
    return 0;
}

//1026//
int main()
{
    char a;
    int b;
    float c;
    double d;
    cin>>a>>b>>c>>d;
    cout<<a<<" "<<b<<" "<<fixed<<setprecision(6)<<c<<" "<<fixed<<setprecision(6)<<d;
}

//1027//
int main()
{
    double n;
    cin>>n;
    printf("%f
",n);
    printf("%.5f
",n);
    printf("%e
",n);
    printf("%g
",n);
    return 0;
}

//1028//
int main()
{
    char v;
    cin>>v;
    cout<<"	"<<v<<endl<<" "<<v<<v<<v<<endl<<v<<v<<v<<v<<v<<endl;
    cout<<" "<<v<<v<<v<<endl<<"	"<<v;
    return 0;
}

//1029//
int main()
{
    double a,b,r;
    cin>>a>>b;
    r=a-int(a/b)*b;
    if(r<0)
       r+=b;
    cout<<r;
}

//1030//
int main()
{
    double r;
    cin>>r;
    cout<<fixed<<setprecision(2)<<(4*3.14*r*r*r)/3.0;
    return 0;
}

//1031//
int main()
{
    int n,a,b,c;
    cin>>n;
    cout<<n%10<<n/10%10<<n/100;
    return 0;
}

//1032//
int main()
{
    double h,r;
    cin>>h>>r;
    cout<<ceil(20.0/(3.14159*r*r*h/1000.0));
    return 0;
}

//1033//
int main()
{
    double Xa,Xb,Ya,Yb;
    cin>>Xa>>Ya>>Xb>>Yb;
    cout<<fixed<<setprecision(3)<<sqrt((Xa-Xb)*(Xa-Xb)+(Ya-Yb)*(Ya-Yb));
    return 0;
}

//1034//
int main()
{
  double x1,x2,x3,y1,y2,y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  cout<<fixed<<setprecision(2)<<sqrt((sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))+sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))/2.0*((sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))+sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))/2.0-sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))*((sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))+sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))/2.0-sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)))*((sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))+sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))/2.0-sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))));
  return 0;
}*/

//1035//
int main()
{
    int a1,a2,n;
    cin>>a1>>a2>>n;
    cout<<a1+(n-1)*(a2-a1);
    return 0;
}
/*
//1129//
int main()
{
    char s[256];
    int ans=0,i;
    gets(s);
    for(i=0;i<=strlen(s);i++)
        if(s[i]>='0'&&s[i]<='9')
            ans++;
    cout<<ans;
    return 0;
}

//1130//
int main()
{
    int letters[26],len,i;
    memset(letters,0,sizeof(letters));
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)
        letters[s[i]-'a']++;
    for(i=0;i<len;i++)
    {
        if(letters[s[i]-'a']==1)
        {
            cout<<s[i];
            return 0;
        }
    }
    cout<<"no";
    return 0;
}

//1131//
int main()
{
    char s1[501],s2[501];
    int len;
    double x,ans=0;
    cin>>x>>s1>>s2;
    len=strlen(s1);
    for(int i=1;i<=len;i++)
        if(s1[i]==s2[i])
            ans++;
    (ans/len>=x)?cout<<"yes":cout<<"no";
    return 0;
}

//1132//
int main()
{
    int n;
    cin>>n;
    char a[n+1],b[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a[0]=='R'&&b[0]=='S'||a[0]=='S'&&b[0]=='P'||a[0]=='P'&&b[0]=='R')
            cout<<"Player1"<<endl;
                else
                    if(a[0]==b[0])
                        cout<<"Tie"<<endl;
                            else
                                cout<<"Player2"<<endl;
    }
    return 0;
}

//1157//
int main()
{
    int x,i;
    for(x=6;x<=100;x+=2)
        for(i=2;i<=x/2;i++)
            if(judge(i)&&judge(x-i))
            {
                cout<<x<<"="<<i<<"+"<<x-i<<endl;
                break;
            }
    return 0;
}

//1397//
int main()
{
    int x,y;
    char z;
    cin>>x>>z>>y;
    cout<<calculate(x,z,y);
    return 0;
}

//1398//
int main()
{
    int n,a,i;
    double sum=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        sum+=calculate1(a);
    }
    printf("%.1lf
",sum/10.0);
    return 0;
}

//1399//
int main()
{
    int n,sum=0,i;
    cin>>n;
    float temperature[n+1];
    int cough[n+1];
    string name[n+1];
    for(i=1;i<=n;i++)
        cin>>name[i]>>temperature[i]>>cough[i];
    for(i=1;i<=n;i++)
        if(judge1(temperature[i],cough[i]))
        {
            cout<<name[i]<<endl;
            sum++;
        }
    cout<<sum;
    return 0;
}*/



//\u51fd\u6570\u90e8\u5206//
int calculate1(int x)
{
    if(x%70==0)
        return x/70;
    else
        return x/70+1;
}

int calculate(int x,char z,int y)
{
    if (z == '+') return x + y;
    if (z == '-') return x - y;
    if (z == '*') return x * y;
    if (z == '/') return x / y;
    if (z == '%') return x % y;
}

bool judge(int x)
{
    int i;
    for(i=2;i<=floor(sqrt(x))&&(x%i!=0);i++);
    if(i>floor(sqrt(x)))
        return true;
    return false;
}


bool judge1(float x,int y)
{
    if((x>=37.5)&&(y==1))
        return true;
    else
        return false;
}
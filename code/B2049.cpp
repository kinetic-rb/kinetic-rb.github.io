//\u6587\u4ef6\u5934//
#include<bits/stdc++.h>
using namespace std;

//\u51fd\u6570\u6846\u67b6//

//bool//
bool judge(int x);
bool judge1(float x,int y);

//int//
int calculate(int x,char z,int y);
int calculate1(int x);

//\u5168\u5c40\u53d8\u91cf//

//char//
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
}

//1035//
int main()
{
    int a1,a2,n;
    cin>>a1>>a2>>n;
    cout<<a1+(n-1)*(a2-a1);
    return 0;
}

//1036//
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<(long long)a*b;
    return 0;
}

//1037//
int main()
{
    int n;
    cin>>n;
    cout<<int(pow(2,n));
    return 0;
}

//1038//
int main()
{
    double n,x,y,c;
    cin>>n>>x>>y;
    c=n-ceil(y*1.0/x);
    if(c<0)
        c=0;
    cout<<c<<endl;
    return 0;
}

//1039//
int main()
{
    int n;
    cin>>n;
    if(n>0)
        cout<<"positive";
            else
                if(n<0)
                    cout<<"negative";
                        else
                            cout<<"zero";
    return 0;
}

//1040//
int main()
{
    double v;
    cin>>v;
    cout<<abs(v);
    return 0;
}

//1041//
int main()
{
    int v;
    cin>>v;
    (v%2)?cout<<"odd":cout<<"even";
    return 0;
}

//1042//
int main()
{
    char v;
    cin>>v;
    (int(v)%2)?cout<<"YES":cout<<"NO";
    return 0;
}

//1043//
int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
        cout<<">";
            else
                if(a<b)
                    cout<<"<";
                        else
                            cout<<"=";
    return 0;
}

//1044//
int main()
{
    int v;
    cin>>v;
    (v>9&&v<100)?cout<<"1":cout<<"0";
    return 0;
}

//1045//
int main()
{
    int xy,gl;
    cin>>xy>>gl;
    (xy>9||gl>19)?cout<<"1":cout<<"0";
    return 0;
}

//1046//
int main()
{
    int v;
    cin>>v;
    (v%15)?cout<<"NO":cout<<"YES";
    return 0;
}

//1047//
int main()
{
    bool b3=false,b5=false,b7=false;
    int v;
    cin>>v;
    if(!(v%3))
        b3=true;
    if(!(v%5))
        b5=true;
    if(!(v%7))
        b7=true;
    if(!(b3&&b5&&b7))
    {
        cout<<"n";
        return 0;
    }
    if(b3)
        cout<<"3 ";
    if(b5)
        cout<<"5 ";
    if(b7)
        cout<<"7 ";
    return 0;
}

//1048//
int main()
{
    int c,m;
    cin>>c>>m;
    (c<60^m<60)?cout<<"1":cout<<"0";
}

//1049//
int main()
{
    int d;
    cin>>d;
    (d!=1&&d!=3&&d!=5)?cout<<"YES":cout<<"NO";
    return 0;
}

//1050//
int main()
{
  float v;
  cin>>v;
  if(27+23+v/3.0>v/1.2)
        printf("Walk");
          else
              if(27+23+v/3.0<v/1.2)
                  printf("Bike");
                      else
                            printf("All");
  return 0;
}

//1051//
int main()
{
    double x;
    cin>>x;
    if(0<=x&&x<5)
        printf("%.3lf",2.5-x);
            else
                if(5<=x&&x<10)
                    printf("%.3lf",2-1.5*(x-3)*(x-3));
                        else
                            if(10<=x&&x<20)
                                printf("%.3lf",x/2.0-1.5);
    return 0;
}

//1052//
int main()
{
  int weight,money;
    char c;
    cin>>weight>>c;
    (weight>1000)?money=8+ceil((weight-1000)/500.0)*4:money=8;
    if(c=='y')
        money+=5;
    cout<<money;
    return 0;
}*/

//1053//
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(max(a,b),c);
    return 0;
}/*

//1054//
int main()
{
    int v[3];
    cin>>v[0]>>v[1]>>v[2];
    if(v[0]>v[1])
        swap(v[0],v[1]);
    if(v[1]>v[2])
        swap(v[1],v[2]);
    if(v[0]>v[1])
        swap(v[0],v[1]);
    (v[0]+v[1]>v[2])?cout<<"yes":cout<<"no";
    return 0;
}

//1055//
int main()
{
    int v;
    cin>>v;
    (!(v%4)&&v%100||!(v%400))?cout<<"Y":cout<<"N";
    return 0;
}

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



//\u51fd\u6570\u90e8\u5206(\u5177\u4f53\u5b9e\u73b0)//

//bool//
bool judge(int x)
{
    int i;
    for(i=2;i<=floor(sqrt(x))&&(x%i!=0);i++);
    return (i>floor(sqrt(x)))?true:false;
}

bool judge1(float x,int y)
{
    return ((x>=37.5)&&(y==1))?true:false;
}

//int//
int calculate1(int x)
{
    return (x%70==0)?x/70:x/70+1;
}

int calculate(int x,char z,int y)
{
    if(z=='+') return x+y;
    if(z=='-') return x-y;
    if(z=='*') return x*y;
    if(z=='/') return x/y;
    if(z=='%') return x%y;
}
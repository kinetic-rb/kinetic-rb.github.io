//\u6587\u4ef6\u5934//
#include<bits/stdc++.h>
using namespace std;

//ybt//

//---------------//

//\u81ea\u5b9a\u4e49\u6570\u636e\u7c7b\u578b//
struct tQue
{
    int a[200],head,tail;
};//ybt//
struct stu
{
    int num,c,m,e,sum;
}student[300];//ybt//
struct point
{
    int num,val;
}ioa2[500010];//luogu//

//\u81ea\u5b9a\u4e49//
#define precision_1 1e-12
#define precision_2 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 1001
#define MOD 123
#define E 1e-6
#define MAXL 1001
#define Long long long

//\u51fd\u6570\u6846\u67b6(all[both "ybt" and "luogu"])//

//bool//
bool judge1(float x,int y);//ybt//
bool judge(int x);//ybt//
bool iocmp(stu a,stu b);//ybt//

//double//
double Hermite(int n,int x);//ybt//
double f_x_n(double x,double n);//ybt//
double fxn(double x,double n);//ybt//
double CPI(double x);//ybt//

//int//
int calculate(int x,char z,int y);//ybt//
int Ackmann(int m,int n);//ybt//
int calculate1(int x);//ybt//
int calculate2(int n);//ybt//
int digit(int n,int k);//ybt//
int Fib(int n);//ybt//

//void//
void Low_To_High(int n);//ybt//
void del_er_ly_ing(char s[]);//ybt//
void push(tQue &q,int x);//ybt//
void work(int a,int n);//ybt//
void bfs();//ybt//
void C_Nton(int n,int k);//ybt//
void turn(char &x);//ybt//
void gsy(int a[],int len_s,char s[]);//ybt//
void msort(int b,int e,int a[],int c[],long long ans);//luogu//

//other//
inline bool cmp(point q,point w);//luogu//
inline void insert(int p,int d);//luogu//
inline int query(int p);//luogu//

//\u5168\u5c40\u53d8\u91cf//

//char//
char ios[100001];//ybt//

//int//
int iotree[500010],iorank[500010],ioN;//luogu//
int iotu[101][101],iodr[4][2]={{-1,0},{1,0},{0,-1},{0,1}},ion,iom,ioq[10001],iohead,iotail,ioans;//ybt//

//long long//
long long ioQ[1000010];//ybt//
long long ans;//luogu//

//\u7a0b\u5e8f\u90e8\u5206(ybt)//
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
    double b;
    float a;
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
    bool V;
    int v;
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
    double d;
    float c;
    int b;
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
    char c;
  int weight,money;
    cin>>weight>>c;
    (weight>1000)?money=8+ceil((weight-1000)/500.0)*4:money=8;
    if(c=='y')
        money+=5;
    cout<<money;
    return 0;
}

//1053//
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(max(a,b),c);
    return 0;
}

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

//1056//
int main()
{
    int x,y;
    cin>>x>>y;
    ((x>=-1&&x<=1)&&(y>=-1&&y<=1))?cout<<"yes":cout<<"no";
    return 0;
}

//1057//
int main()
{
    bool v=false;
    char c;
    int a,b;
    cin>>a>>b>>c;
    switch(c)
    {
        case '+' : cout<<a+b;break;
        case '-' : cout<<a-b;break;
        case '*' : cout<<a*b;break;
        case '/' : v=true;break;
        default : cout<<"Invalid operator!";
    }
    if(v)
        (!b)?cout<<"Divided by zero!":cout<<a/b;
    return 0;
}

//1058//
int main()
{
    double a,b,c,x1,x2,delta;
    cin>>a>>b>>c;
    delta=b*b-4*a*c;
    if(delta<0&&fabs(delta)>precision_1)
        printf("No answer!
");
            else
                if(fabs(delta)<precision_1)
                {
                    x1=-b/(2*a);
                    (fabs(x1)<precision_2)?printf("x1=x2=%.5lf
",0):printf("x1=x2=%.5lf
",x1);
                }
                    else
                    {
                        x1=(-b+sqrt(delta))/(2*a);
                        x2=(-b-sqrt(delta))/(2*a);
                        if(fabs(x1)<precision_2)
                            x1=fabs(x1);
                        if(fabs(x2)<precision_2)
                            x2=fabs(x2);
                        printf("x1=%.5lf;x2=%.5lf",min(x1,x2),max(x1,x2));
                    }
    return 0;
}

//1059//
int main()
{
    int n,s=0,t;
    cin>>n;
    for(int i=0;i<n;i++,s+=t)
        cin>>t;
    cout<<fixed<<setprecision(2)<<s*1.0/n;
    return 0;
}

//1060//
int main()
{
    int n;
    double s=0,t;
    cin>>n;
    for(int i=0;i<n;i++,s+=t)
        cin>>t;
    cout<<fixed<<setprecision(4)<<s*1.0/n;
    return 0;
}

//1061//
int main()
{
    double n,s=0,t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        s+=t;
    }
    cout<<s<<" "<<fixed<<setprecision(5)<<s*1.0/n;
    return 0;
}

//1062//
int main()
{
    int n,t,MAX;
    cin>>n;
    cin>>t;
    MAX=t;
    for(int i=1;i<n;i++)
    {
        cin>>t;
        MAX=max(MAX,t);
    }
    cout<<MAX;
    return 0;
}

//1063//
int main()
{
    int n,t,MAX,MIN;
    cin>>n;
    cin>>t;
    MAX=MIN=t;
    for(int i=1;i<n;i++)
    {
        cin>>t;
        MAX=max(MAX,t);
        MIN=min(MIN,t);
    }
    cout<<MAX-MIN;
    return 0;
}

//1064//

int main()
{
    int n;
    cin>>n;
    int a[n][3];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        a[0][0]+=a[i][0];
        a[0][1]+=a[i][1];
        a[0][2]+=a[i][2];
    }
    cout<<a[0][0]<<" "<<a[0][1]<<" "<<a[0][2]<<" "<<a[0][0]+a[0][1]+a[0][2];
    return 0;
}

//1065//
int main()
{
    int m,n,sum;
    cin>>m>>n;
    if(!(m%2))
        m++;
    for(sum=0;m<=n;m+=2)
        sum+=m;
    cout<<sum;
    return 0;
}

//1066//
int main()
{
    int m,n,sum;
    cin>>m>>n;
    for(sum=0;m<=n;m++)
        if(!(m%17))
            sum+=m;
    cout<<sum;
    return 0;
}

//1067//
int main()
{
    int k,t,s1=0,s5=0,s10=0;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>t;
        switch(t)
        {
            case 1 : s1++;break;
            case 5 : s5++;break;
            case 10 : s10++;break;
        }
    }
    cout<<s1<<endl<<s5<<endl<<s10;
    return 0;
}

//1068//
int main()
{
    int n,m,t,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t==m)
            ans++;
    }
    cout<<ans;
    return 0;
}

//1069//
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<(long long)pow(a,n);
    return 0;
}

//1070//
int main()
{
    int n;
    double x;
    cin>>x>>n;
    for(int i=0;i<n;i++)
        x+=x/1000.0;
    cout<<fixed<<setprecision(4)<<x;
    return 0;
}

//1071//
int main()
{
    int fb[46]={1,1},k;
    cin>>k;
    for(int i=2;i<k;i++)
        fb[i]=fb[i-1]+fb[i-2];
    cout<<fb[k-1];
    return 0;
}

//1072//
int main()
{
    double x,y;
    int n,sy[20][2];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>sy[i][0]>>sy[i][1];
    x=sy[0][1]*1.0/sy[0][0];
    for(int i=1;i<n;i++)
    {
        y=sy[i][1]*1.0/sy[i][0];
        if(y-x>0.05)
            cout<<"better"<<endl;
                else
                    if(x-y>0.05)
                        cout<<"worse"<<endl;
                            else
                                cout<<"same"<<endl;
    }
    return 0;
}

//1082//
int main()
{
  int a,b,n,d;
  cin>>a>>b>>n;
  a%=b;
  for(int i=0;i<n;i++)
  {
    d=a*10/b;
    a=a*10%b;
  }
  cout<<d;
  return 0;
}

//1083//
int main()
{
    long long a,b,dy;
    cin>>a>>b;
    dy=a;
    for(int i=1;i<b;i++)
        dy=dy*a%7;
    switch(dy)
    {
        case 0 : printf("Sun");break;
        case 1 : printf("Mon");break;
        case 2 : printf("Tues");break;
        case 3 : printf("Wednes");break;
        case 4 : printf("Thurs");break;
        case 5 : printf("Fri");break;
        case 6 : printf("Satur");
    }
    cout<<"day";
    return 0;
}

//1084//
int main()
{
  long long a,b,ans;
  cin>>a>>b;
  ans=a;
  for(int i=1;i<b;i++)
    ans=ans*a%1000;
  if(ans<=9)
    cout<<"00"<<ans;
  else if(ans<=99)
    cout<<'0'<<ans;
  else
    cout<<ans;
  return 0;
}

//1092//
int main()
{
    double e=1;
    int n;
    long long temp=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        temp*=i;
        e+=1.0/temp;
    }
    printf("%.10lf",e);
    return 0;
}

//1098//
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++)
        if(!(n%i))
        {
            cout<<n/i;
            break;
        }
    return 0;
}

//1100//
int main()
{
    int day,date=1,sum=0,j=0;
    cin>>day;
    for(int i=0;i<day;i++)
    {
        sum+=date;
        if(i==j)
        {
            date++;
            j+=date;
        }
    }
    cout<<sum;
    return 0;
}

//1111//
int main()
{
    int i,ans[7],max,t[7];
    struct Time
    {
        int x,y;
    };
    Time v[7];
    for(i=0;i<7;i++)
    {
        cin>>v[i].x>>v[i].y;
        t[i]=ans[i]=v[i].x+v[i].y;
    }
    sort(t,t+7);
    max=t[6];
    for(i=0;i<7;i++)
    {
        if(ans[i]==max)
            break;
    }
    cout<<i+1;
    return 0;
}

//1113//
int main()
{
    int Max,n,i;
    long long s=0;
    cin>>n;
    int data[n];
    cin>>Max;
    data[0]=Max;
    for(i=1;i<n;i++)
    {
        cin>>data[i];
        Max=max(Max,data[i]);
    }
    for(i=0;i<n;i++)
        if(data[i]!=Max)
            s+=data[i];
    cout<<s;
    return 0;
}

//1114//
int main()
{
    double n,max=-99999999999999,min=99999999999999,a[3001],b[3001],sum=0,average,ave_max=-99999999999999;
    int flag_max,flag_min,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>max)
        {
            max=a[i];
            flag_max=i;
        }
        if(a[i]<min)
        {
            min=a[i];
            flag_min=i;
        }
        sum+=a[i];
    }
    average=1.0*(sum-max-min)/(n-2);
    for(i=1;i<=n;i++)
    {
        if(i!=flag_max&&i!=flag_min)
        {
            b[i]=a[i]-average;
            if(b[i]<0)
                b[i]=-b[i];
        }
            else
                b[i]=-99999999999999;
    }
    for(i=1;i<=n;i++)
        if(b[i]>ave_max)
            ave_max=b[i];
    printf("%.2lf %.2lf",average,ave_max);
    return 0;
}

//1115//
int main()
{
    int n,x,a[10000],max=-2147483648,i;
    memset(a,0,sizeof(a));
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a[x]++;
        if(x>max)
        max=x;
    }
    for(i=0;i<=max;i++)
        cout<<a[i]<<endl;
    return 0;
}

//1116//
int main()
{
    int n,a[75000],MAX=-2147483648,len=1;
    cin>>n;
    a[0]=-2147483648;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
      (a[i]==a[i-1])?len++:len=1;
      MAX=max(MAX,len);
    }
    cout<<MAX;
    return 0;
}

//1117//
int main()
{
    bool b[20000];
    int n,a[20000],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=true;
    }
    for(i=0;i<n;i++)
        if(b[i])
            for(j=i+1;j<=n;j++)
                if(a[i]==a[j])
                    b[j]=false;
    for(i=0;i<n;i++)
        if(b[i]==true)
            printf("%d ",a[i]);
    return 0;
}

//1118//
int main()
{
    int n,x,y,a[10001],b[10001],g[10001],k[10001],i;
    scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        scanf("%d%d",&g[i],&k[i]);
    }
    scanf("%d%d",&x,&y);
    for(i=n;i>0;i--)
    {
        if((x>=a[i]&&x<=a[i]+g[i])&&(y>=b[i]&&y<=b[i]+k[i]))
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
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
    gets(ios);
    len=strlen(ios);
    for(i=0;i<len;i++)
        letters[ios[i]-'a']++;
    for(i=0;i<len;i++)
    {
        if(letters[ios[i]-'a']==1)
        {
            cout<<ios[i];
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
    double x,ans=0;
    int len;
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
            cout<<"Player1";
                else
                    if(a[0]==b[0])
                        cout<<"Tie";
                            else
                                cout<<"Player2";
    }
    return 0;
}

//1133//
int main()
{
    char a[101];
    int len,i;
    gets(a);
    len=strlen(a);
    for(i=0;i<len-1;i++)
        cout<<char(a[i]+a[i+1]);
    cout<<char(a[len-1]+a[0]);
    return 0;
}

//1134//
int main()
{
    char s[256];
    int len,i;
    gets(s);
    len=strlen(s);
    if(s[0]>='0'&&s[0]<='9')
    {
        cout<<"no";
        return 0;
    }
    for(i=0;i<len;i++)
    {
        if(!((s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||s[i]=='_'))
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}

//1135//
int main()
{
    char s[256];
    gets(s);
    for(int i=0;s[i];i++)
        switch(s[i])
        {
            case 'T' : cout<<"A";break;
            case 'A' : cout<<"T";break;
            case 'C' : cout<<"G";break;
            case 'G' : cout<<"C";
        }
    return 0;
}

//1136//
int main()
{
    char s[256];
    gets(s);
    for(int i=0;i<strlen(s);i++)
        if(s[i]=='Z'||s[i]=='z')
            s[i]-=25;
                else
                    if(s[i]>='A'&&s[i]<'Z')
                        s[i]+=1;
                            else
                                if(s[i]>='a'&&s[i]<'z')
                                    s[i]+=1;
    cout<<s;
    return 0;
}

//1137//
int main()
{
    char s[256],temp;
    int i;
    gets(s);
    for (i=0;i<strlen(s);i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            temp=s[i];
            temp+=3;
            if(temp>122)
                temp-=26;
            temp-=32;
            s[i]=temp;

        }
            else
                if (s[i]>='A'&&s[i]<='Z')
                {
                    temp=s[i];
                    temp+=3;
                    if(temp>90)
                        temp-=26;
                    temp+=32;
                    s[i]=temp;
                }
    }
    for(int i=strlen(s)-1;i>-1;i--)
        cout<<s[i];
    return 0;
}

//1138//
int main()
{
    char s[100],i;
    gets(s);
    for(i=0;i<strlen(s);i++)
        if(s[i]>='a'&&s[i]<='z')
            s[i]+='A'-'a';
    puts(s);
    return 0;
}

//1139//
int main()
{
    char str[25];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        if(str[0]>='a'&&str[0]<='z')
            str[0]-=32;
        for(int j=1;j<strlen(str);j++)
            if(str[j]>='A'&&str[j]<='Z')
                str[j]+=32;
        puts(str);
    }
    return 0;
}

//1140//
int main()
{
    char s1[200],s2[200];
    cin>>s1;
    cin>>s2;
    if(strstr(s2,s1))
    {
        cout<<s1<<" is substring of "<<s2<<endl;
        return 0;
    }
    if(strstr(s1,s2))
    {
        cout<<s2<<" is substring of "<<s1<<endl;
        return 0;
    }
    cout<<"No substring";
    return 0;
}

//1141//
int main()
{
    char s[32],t[32];
    gets(s);
    strcpy(t,s);
    del_er_ly_ing(s);
    (!strlen(s))?cout<<t:cout<<s;
    return 0;
}

//1142//
int main()
{
    char s[1000];
    int len=0,i;
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!=' ')
            len++;
                else
                {
                    if(len>0)
                        cout<<len<<",";
                    len=0;
                }
    }
    cout<<len;
    return 0;
}

//1143//
int main()
{
    char s[10000];
    int sum=0,max_len=0,min_len=9999,max_position,min_position,i;
    gets(s);
    s[strlen(s)]=' ';
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!=' '&&s[i]!=',')
            sum++;
                else
                    if(sum>0)
                    {
                        if(sum>max_len)
                        {
                            max_len=sum;
                            max_position=i-sum;
                        }
        if(sum<min_len)
        {
            min_len=sum;
            min_position=i-sum;
        }
        sum=0;
        }
    }
    for(i=max_position;i<=max_position+max_len-1;i++)
        cout<<s[i];
    cout<<endl;
    for(i=min_position;i<=min_position+min_len-1;i++)
        cout<<s[i];
    return 0;
}

//1144//
int main()
{
    char s[1000];
    int position,sum=0;
    gets(s);
    s[strlen(s)]=' ';
    for(int i=0;i<=strlen(s);i++)
        if(s[i]!=' ')
            sum++;
        else
        {
            position=i;
            for(int j=1;j<=sum;j++)
                cout<<s[--position];
            sum=0;
            if(i!=strlen(s))
                cout<<" ";
        }
    return 0;
}

//1147//
int main()
{
    int n,Max;
    cin>>n;
    struct ts
    {
        int mark;
        char name[20];
    };
    ts v[n];
    cin>>v[0].mark>>v[0].name;
    Max=v[0].mark;
    for(int i=1;i<n;i++)
    {
        cin>>v[i].mark>>v[i].name;
        Max=max(Max,v[i].mark);
    }
    for(int i=0;i<n;i++)
    {
        if(v[i].mark==Max)
        {
            cout<<v[i].name;
            return 0;
        }
    }
    return 0;
}

//1148//
int main()
{
    char s[2500];
    int k,sum=0;
    cin>>k>>s;
    for(int i=0;i<strlen(s);i++)
    {
        if(sum==k)
        {
            cout<<s[i];
            return 0;
        }
        (s[i]==s[i+1])?sum++:sum=1;
    }
    cout<<"No";
    return 0;
}

//1152//
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    cout<<fixed<<setprecision(3)<<max(a,max(b,c))*1.0/(max(a+b,max(b,c))*max(b+c,max(a,b)));
    return 0;
}

//1156//
int main()
{
    double p;
    p=6*(CPI(1/sqrt(3)));
    printf("%.10lf",p);
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

//1158//
int main()
{
    int n;
    cin>>n;
    cout<<calculate2(n);
    return 0;
}

//1159//
int main()
{
    int n;
    cin>>n;
    cout<<Fib(n-1);
    return 0;
}

//1160//
int main()
{
    int n;
    cin>>n;
    Low_To_High(n);
    return 0;
}

//1161//
int main()
{
    int x,m;
    cin>>x>>m;
    C_Nton(x,m);
    return 0;
}

//1162//
int main()
{
    char s[100];
    gets(s);
    for(int i=strlen(s)-1;i>-1;i--)
        if(s[i]!='!')
            cout<<s[i];
    return 0;
}

//1163//
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<Ackmann(m,n);
    return 0;
}

//1164//
int main()
{
   int n,k;
   cin>>n>>k;
   cout<<digit(n,k);
   return 0;
}

//1165//
int main()
{
    int n,x;
    cin>>n>>x;
    printf("%.2lf",Hermite(n,x));
    return 0;
}

//1166//
int main()
{
    double n,x;
    double result;
    cin>>x>>n;
    result=f_x_n(x,n);
    printf("%.2lf",result);
    return 0;
}

//1167//
int main()
{
    double n,x,result;
    cin>>x>>n;
    result=fxn(x,n);
    printf("%.2lf
",result);
    return 0;
}

//1185//
int main()
{
    string a[100];
    int k=0,i;
    bool flag;
    for(flag=false;cin>>a[k];)
    {
        for(i=0;i<k;i++)
            if(!(a[i].compare(a[k])))
            {
                flag=true;
                break;
            }
        if(!flag)
            k++;
    }
    sort(a,a+k);
    for(i=0;i<k;i++)
        cout<<a[i]<<endl;
    return 0;
}

//1189//
int main()
{
    Long pel[1000001],n,t;
    pel[1]=1;
    pel[2]=2;
    for(int j=3;j<1000001;pel[j++]=(2*pel[j-1]+pel[j-2])%32767);
    for(cin>>n;n--;cout<<pel[t]<<endl)
        cin>>t;
    return 0;
}

//1267//
int main()
{
  const int MAXN=210;
  int M,N,f[MAXN],w[MAXN],c[MAXN];
  memset(f,0,sizeof(f));
  cin>>M>>N;
  for(int i=1;i<=N;i++)
    cin>>w[i]>>c[i];
  for(int i=1;i<=N;i++)
    for(int v=M;v>=w[i];v--)
      f[v]=max(f[v],f[v-w[i]]+c[i]);
  cout<<f[M];
  return 0;
}

//1314//
int main()
{
    long long a[30][30];
    int vis[30][30],next[][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}},n,m,x,y,nx,ny,i,j;
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>x>>y;
    a[0][0]=0;
    vis[x][y]=1;
    a[x][y]=0;
    for(i=0;i<8;i++)
    {
        nx=x+next[i][0];
        ny=y+next[i][1];
        if(0<=nx&&nx<=n&&0<=ny&&ny<=m)
        {
            vis[nx][ny]=1;
            a[nx][ny]=0;
        }
    }
    for(i=0;i<=n;i++)
    {
        if(vis[i][0]==1)
            while(i<=n)
            {
                i++;
                a[i][0]=0;
            }
                else
                    a[i][0]=1;
    }
    for(j=0;j<=m;j++)
    {
        if(vis[0][j]==1)
            while(j<=m)
            {
                j++;
                a[0][j]=0;
            }
                else
                    a[0][j]=1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(!(vis[i][j]))
                a[i][j]=a[i][j-1]+a[i-1][j];
    cout<<a[n][m];
    return 0;
}

//1331//
int main()
{
    char str[10005];
    stack<long long> S;
    gets(str);
    int len=strlen(str)-1;
    for(int i=0;i<len;i++)
        switch(str[i])
        {
            case '+':
            {
                long long y=S.top();S.pop();
                long long x=S.top();S.pop();
                S.push(x+y);
                break;
            }
            case '-':
            {
                long long y=S.top();S.pop();
                long long x=S.top();S.pop();
                S.push(x-y);
                break;
            }
            case '*':
            {
                long long y=S.top();S.pop();
                long long x=S.top();S.pop();
                S.push(x*y);
                break;
            }
            case '/':
            {
                long long y=S.top();S.pop();
                long long x=S.top();S.pop();
                S.push(x/y);
                break;
            }
            case '@':
            {
                i=len;
                break;
            }
            default:
            {
                long long temp=0;
                while(str[i]!=' ')
                    temp=temp*10+str[i]-'0',i++;
                S.push(temp);
                break;
            }
        }
    cout<<S.top();
    return 0;
}

//1332//
int main()
{  int m,w,c,t;
    tQue qM,qW;
    scanf("%d%d%d",&m,&w,&c);
    qM.head=qM.tail=0;
    qW.head=qW.tail=0;
    for(int i=1;i<=m;i++)
        push(qM,i);
    for(int i=1;i<=w;i++)
        push(qW,i);
    for(int i=1;i<=c;i++)
    {  printf("%d %d
",qM.a[qM.head],qW.a[qW.head]);
        t=qM.a[qM.head];
        qM.head++;
        push(qM,t);
        t=qW.a[qW.head];
        qW.head++;
        push(qW,t);
    }
    return 0;
}

//1333//
int main()
{
    int a,n;
    while(cin>>a>>n)
        work(a,n);
    return 0;
}

//1334//
int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    queue<int> Q;
    for(int i=1;i<=n;i++)
        Q.push(i);
    while(!Q.empty())
    {
        cnt++;
        int temp=Q.front();
        if(cnt==m)
        {
            cnt=0;
            cout<<temp<<" ";
        }
            else
                Q.push(temp);
        Q.pop();
    }
    return 0;
}

//1335//
int main()
{  cin>>ion>>iom;
  for(int i=1;i<=ion;i++)
    for(int j=1;j<=iom;j++)
        cin>>iotu[i][j];
  for(int i=1;i<=ion;i++)
    for(int j=1;j<=iom;j++)
    {
        if(!iotu[i][j])
            continue;
      ioans++;
      iohead=iotail = 0;
      ioq[iotail++]=i;
      ioq[iotail++]=j;
      bfs();
    }
  cout<<ioans;
  return 0;
}

//1353//
int main()
{
    int tot=0;
    char s[256];
    cin>>s;
    for(int i=0;s[i]!='@';i++)
    {
        if(s[i]=='(')
            tot++;
        if(s[i]==')')
            if(tot>-1)
                tot--;
                    else
                        break;
    }
    (tot)?cout<<"NO":cout<<"YES";
    return 0;
}

//1354//
int main()
{
    char a[256];
    string s;
    int t=0;
    cin>>s;
    for(int j=0;j<=s.size()-1;j++)
    {
        if(s[j]=='('||s[j]=='[')
            a[++t]=s[j];
        if(s[j]==')')
            (a[t]=='(')?t--:t++;
        if(s[j]==']')
            (a[t]=='[')?t--:t++;
    }
    (!t)?cout<<"OK":cout<<"Wrong";
    return 0;
}

//1355//
int main()
{
    stack<int> S;
    char a[]={'{','[','(','<','}',']',')','>'},str[300];
    int b[300],x;
    cin>>x;
    while(x--)
    {
        while(!S.empty())
            S.pop();
        bool flag=true;
        cin>>str;
        int len=strlen(str);
        for(int i=0;i<len;i++)
            for(int j=0;j<8;j++)
                if(str[i]==a[j])
                {
                    b[i]=j;
                    break;
                }
        for(int i=0;i<len;i++)
        {
            if(b[i]<=3)
            {
                if(!S.empty()&&b[i]<S.top())
                {
                    flag=false;
                    break;
                }
                    else
                        S.push(b[i]);
            }
                else
                    if(b[i]>=4)
                    {
                        if(S.empty()||(S.top()+4)!=b[i])
                        {
                            flag=false;
                            break;
                        }
                            else
                                S.pop();
                    }
        }
        if(!S.empty())
            cout<<"NO"<<endl;
                else
                    if(flag==1)
                        cout<<"YES"<<endl;
                            else
                                cout<<"NO"<<endl;
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
}

//1400//
int main()
{
    string word,sentence;
    int j,ans=0,direction;
    getline(cin,word);
    getline(cin,sentence);
    for(int i=0;i<sentence.size();i++)
    {
        for(j=0;j<word.size();j++)
        {
            if(toupper(sentence[i+j])!=toupper(word[j]))
                break;
            if(i>0&&sentence[i-1]!=' ')
                break;
        }
        if(j==word.size()&&(sentence[i+j]==' '||j+i==sentence.size()))
        {
            ans++;
            if(ans==1)
                direction=i;
        }
    }
    (ans)?cout<<ans<<" "<<direction:cout<<"-1";
    return 0;
}

//1402//
int main()
{
    char key[1000],secret[1000];
    int i,j;
    gets(key);
    gets(secret);
    for(i=0;i<strlen(key);i++)
        turn(key[i]);
    for(i=j=0;i<strlen(secret);i++)
    {
        if(secret[i]<='Z')
        {
            secret[i]=secret[i]-(key[j]-'A');
            j++;
            if(secret[i]<'A')
                secret[i]='Z'-('A'-secret[i])+1;
        }
        else
        {
            secret[i]=secret[i]-(key[j]-'A');
            j++;
            if(secret[i]<'a')
                secret[i]='z'-('a'-secret[i])+1;
        }
        if(j>strlen(key)-1)
            j=0;
    }
    cout<<secret;
    return 0;
}

//1404//
int main()
{
    int n,x;
    cin>>n;
    for(int i=sqrt(6+2*n)-1;;i++)
    {
        if((i*i+i-2*n)%6==0)
        {
            x=(i*i+i-2*n)/6;
            if(x<=0)
                continue;
            if(x>0)
            {
                cout<<x<<" "<<i;
                break;
            }
        }
    }
    return 0;
}

//1406//
int main()
{
    char sp;
    int n=0;
    string str[101],a,b;
    do
    {
        n++;
        cin>>str[n];
        scanf("%c",&sp);
    }
    while(sp==' ');
    cin>>a>>b;
    for(int i=1;i<=n;i++)
        (str[i]==a)?cout<<b<<" ":cout<<str[i]<<" ";
    return 0;
}

//1931//
int main()
{
    int l,m,x,y,t;
    cin>>l>>m;
    bool hs[l+1];
    memset(hs,true,sizeof(hs));
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        t=x+y;
        x=max(x,y);
        for(y=t-x;y<=x;hs[y++]=false);
    }
    for(int i=t=0;i<l+1;i++)
        if(hs[i])
            t++;
    cout<<t;
    return 0;
}*/

//1938//
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        student[i].num=i;
        cin>>student[i].c>>student[i].m>>student[i].e;
        student[i].sum=student[i].c+student[i].m+student[i].e;
    }
    sort(student+1,student+1+n,iocmp);
    for(int i=1;i<=5;i++)
        cout<<student[i].num<<' '<<student[i].sum<<endl;
    return 0;
}/*

*/

//\u51fd\u6570\u90e8\u5206(\u5177\u4f53\u5b9e\u73b0[ybt])//

//bool//
bool judge(int x)
{
    int i;
    for(i=2;i<=floor(sqrt(x))&&(x%i!=0);i++);
    return(i>floor(sqrt(x)))?true:false;
}
bool judge1(float x,int y)
{
    return((x>=37.5)&&(y==1))?true:false;
}
bool iocmp(stu a,stu b)
{
    if(a.sum>b.sum) return 1;
    else if(a.sum<b.sum) return 0;
    else
    {
        if(a.c>b.c) return 1;
        else if(a.c<b.c) return 0;
        else
        {
            if(a.num>b.num) return 0;
            else return 1;
        }
    }
}

//double//
double Hermite(int n,int x)
{
    if(!n)
        return 1;
    if(n==1)
        return 2*x;
    return 2*x*Hermite(n-1,x)-2*(n-1)*Hermite(n-2,x);
}
double f_x_n(double x,double n)
{
    return(n==1)?sqrt(1+x):sqrt(n+f_x_n(x,n-1));
}
double fxn(double x,double n)
{
    return(n==1)?x/(1+x):x/(n+fxn(x,n-1));
}
double CPI(double x)
{
    double sum=0,temp=x;
    for(int i=1;fabs(temp/i)>=1e-6;i+=2)
    {
        sum+=temp/i;
        temp=-1*x*x*temp;
    }
    return sum;
}

//int//
int calculate(int x,char z,int y)
{
    if(z=='+') return x+y;
    if(z=='-') return x-y;
    if(z=='*') return x*y;
    if(z=='/') return x/y;
    if(z=='%') return x%y;
}
int Ackmann(int m,int n)
{
    if(!m)
        return n+1;
    if(m>0&&!n)
        return Ackmann(m-1,1);
    return Ackmann(m-1,Ackmann(m,n-1));
}
int calculate1(int x)
{
    return(x%70==0)?x/70:x/70+1;
}
int calculate2(int n)
{
    return(!n)?0:n+calculate2(n-1);
}
int digit(int n,int k)
{
    int v[k];
    for(int i=0;i<k;i++)
        v[i]=n/pow(10,i);
    return v[k-1]%10;
}
int Fib(int n)
{
    return(n<3)?1:Fib(n-1)+Fib(n-2);
}

//void//
void Low_To_High(int n)
{
    cout<<n%10;
    if(n>9)
        Low_To_High(n/10);
    return;
}
void del_er_ly_ing(char s[])
{
    if(s[strlen(s)-2]=='e'&&s[strlen(s)-1]=='r')
    {
        s[strlen(s)-2]=0;
        return;
    }
    if(s[strlen(s)-2]=='l'&&s[strlen(s)-1]=='y')
    {
        s[strlen(s)-2]=0;
        return;
    }
    if(s[strlen(s)-3]=='i'&&s[strlen(s)-2]=='n'&&s[strlen(s)-1]=='g')
    {
        s[strlen(s)-3]=0;
        return;
    }
}
void push(tQue &q,int x)
{
    q.a[q.tail++]=x;
}
void work(int a,int n)
{
    int rear=2;
    ioQ[1]=a;
    int two=1,three=1;
    while(rear<=n)
    {
        long long t1=ioQ[two]*2+1,t2=ioQ[three]*3+1;
        int t=min(t1,t2);
        (t1<t2)?two++:three++;
        if(t==ioQ[rear-1])
            continue;
        ioQ[rear++]=t;
    }
    cout<<ioQ[n]<<endl;
}
void bfs()
{  while(iohead<iotail)
    {  int x=ioq[iohead++],y=ioq[iohead++];
        for(int i=0;i<4;i++)
        {  int x1=x+iodr[i][0],y1=y+iodr[i][1];
            if(x1>=1&&x1<=ion&&y1>=1&&y1<=iom&&iotu[x1][y1])
            {  iotu[x1][y1]=0;
                ioq[iotail++]=x1;
                ioq[iotail++]=y1;
            }
        }
    }
}
void C_Nton(int n,int k)
{
    char num[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int temp;
    temp=n%k;
    n/=k;
    if(n!=0)
        C_Nton(n,k);
    cout<<num[temp];
}
void turn(char &x)
{
    if((x>='a')&&(x<='z'))
        x-=32;
}
void gsy(int a[],int len_s,char s[])
{
    for(int i=0;i<len_s;i++)
    {
        if(s[i]=='{')
            a[i+1]=1;
        if(s[i]=='[')
            a[i+1]=2;
        if(s[i]=='(')
            a[i+1]=3;
        if(s[i]=='<')
            a[i+1]=4;
        if(s[i]=='>')
            a[i+1]=5;
        if(s[i]==')')
            a[i+1]=6;
        if(s[i]==']')
            a[i+1]=7;
        if(s[i]=='}')
            a[i+1]=8;
    }
}

//---------------//


//\u7a0b\u5e8f\u90e8\u5206(luogu)//

//---------------//
/*
//p1000//
int main()
{
    printf(
            "                ********
"
            "               ************
"
            "               ####....#.
"
            "             #..###.....##....
"
            "             ###.......######              ###            ###
"
            "                ...........               #...#          #...#
"
            "               ##*#######                 #.#.#          #.#.#
"
            "            ####*******######             #.#.#          #.#.#
"
            "           ...#***.****.*###....          #...#          #...#
"
            "           ....**********##.....           ###            ###
"
            "           ....****    *****....
"
            "             ####        ####
"
            "           ######        ######
"
            "##############################################################
"
            "#...#......#.##...#......#.##...#......#.##------------------#
"
            "###########################################------------------#
"
            "#..#....#....##..#....#....##..#....#....#####################
"
            "##########################################    #----------#
"
            "#.....#......##.....#......##.....#......#    #----------#
"
            "##########################################    #----------#
"
            "#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#
"
            "##########################################    ############
"
    );
    return 0;
}

//1177//
int main()
{
    int s[100000],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n);
    for(int i=0;i<n;i++)
        cout<<s[i]<<" ";
    return 0;
}

//p1706//
int main()
{
    int n,i=1,j,k,P[10];
    cin>>n;
    for(j=1;i<=n;i++)
    {
        P[i]=n-i+1;
        j*=i;
    }
    for(i=1;i<=j;i++)
    {
        next_permutation(P+1,P+n+1);
        for(k=1;k<=n;k++)
            cout<<"    "<<P[k];
        printf("\n");
    }
    return 0;
}

//1908//
int main()
{
    scanf("%d",&ioN);
    for(int i=1;i<=ioN;i++)
        scanf("%d",&ioa2[i].val),ioa2[i].num=i;
    sort(ioa2+1,ioa2+1+ioN,cmp);
    for(int i=1;i<=ioN;i++)
        iorank[ioa2[i].num]=i;
    for(int i=1;i<=ioN;i++)
    {
        insert(iorank[i],1);
        ans+=i-query(iorank[i]);
    }
    printf("%lld",ans);
    return 0;
}

//p3378//
int main()
{
    priority_queue<int,vector<int>,greater<int> >heap;
    int n,ob,b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ob);
        if(ob==1)
        {
            scanf("%d",&b);
            heap.push(b);
        }
        if(ob==2)
        {
            printf("%d
",heap.top());
        }
        if(ob==3)
            heap.pop();
    }
    return 0;
}*/

//\u51fd\u6570\u90e8\u5206(\u5177\u4f53\u5b9e\u73b0[luogu])//

//void//
void msort(int b,int e,int a[],int c[],long long ans)
{
    if(b==e)
    return;
    int mid=(b+e)/2,i=b,j=mid+1,k=b;
    msort(b,mid,a,c,ans),msort(mid+1,e,a,c,ans);
    while(i<=mid&&j<=e)
      (a[i]<=a[j])?c[k++]=a[i++]:c[k++]=a[j++],ans+=mid-i+1;
    while(i<=mid)
      c[k++]=a[i++];
    while(j<=e)
      c[k++]=a[j++];
    for(int l=b;l<=e;l++)
      a[l]=c[l];
}

//other//
inline bool cmp(point q,point w)
{
    if(q.val==w.val)
        return q.num<w.num;
    return q.val<w.val;
}
inline void insert(int p,int d)
{
    for(;p<=ioN;p+=p&-p)
        iotree[p]+=d;
}
inline int query(int p)
{
    int sum=0;
    for(;p;p-=p&-p)
        sum+=iotree[p];
    return sum;
}

//---------------//

//working place//
#include<cmath>
#include<iomanip>
#include<iostream>
using namespace std;

short x,y,x2,y2,x3,y3;
double r,mx1,my1,mx2,my2,k1,k2,b1,b2,X,Y;

int main(){
    ios::sync_with_stdio(0);
\tcin>>x>>y>>x2>>y2>>x3>>y3;
\tk1=1.0*(y-y2)/(x-x2);
\tk2=1.0*(y-y3)/(x-x3);
\tif(k1==k2)cout<<"Line";
\telse{
\t\tk1=-1/k1,k2=-1/k2;
\t\tmx1=(x+x2)/2.0,my1=(y+y2)/2.0,mx2=(x+x3)/2.0,my2=(y+y3)/2.0;
\t\tb1=my1-k1*mx1,b2=my2-k2*mx2;
\t\tX=(b2-b1)/(k1-k2),Y=(k1*b2-k2*b1)/(k1-k2);
\t\tcout<<fixed<<setprecision(2)<<X<<" "<<fixed<<setprecision(2)<<Y;
\t\tr=hypot(X-x,Y-y);
\t\tcout<<endl<<r;
\t}
\treturn 0;
}
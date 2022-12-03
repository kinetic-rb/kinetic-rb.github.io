#include<iostream>
using namespace std;
int main(){long double m,h;cin>>m>>h;
long double i=m/(h*h);
if(i<18.5){cout<<"Underweight"<<endl;}
if(i>=18.5&&i<24){cout<<"Normal"<<endl;}
if(i>=24){cout<<i<<endl<<"Overweight"<<endl;}

return 0;
}
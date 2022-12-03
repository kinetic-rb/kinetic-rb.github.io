#include<bits/stdc++.h>
using namespace std;
long long n = 49,a[4],i,j,s;
int b[51];
int main(){
\tcin >> a[1] >> a[2] >> a[3];
\tfor(i = 1; i <= 3; i++){
\t\tfor(j = n; j >= 0; j--){
\t\t\tif(a[i] >= pow(2,j)){
\t\t\t\ta[i] -= pow(2,j);
\t\t\t\tb[j]++;
\t\t\t}
\t\t}
\t}
\tfor(i = 0; i <= n; i++){
        if(b[i] == 3) s++;
    }
    cout<< s << endl;
\treturn 0;
}
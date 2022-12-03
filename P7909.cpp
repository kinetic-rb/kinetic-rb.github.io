#include<bits/stdc++.h>
using namespace std;
int main(){
\tios::sync_with_stdio(0);
\tcin.tie(0);
\tcout.tie(0);
\tbool f=0;
\tint r,l,ren,i;
\tcin>>ren>>l>>r;
\tint chu=r/ren;
\tfor(i=1;i<ren;i++){
\t\tif(chu*ren-i>=l){
\t\t\tf=1;
\t\t\tbreak;
\t\t}
\t\tif(chu*ren+i>r) break;
\t}
\tif(f) cout<<ren-i;
\telse cout<<i-1;
\treturn 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
    cin >> n;
    for(int i = 3; i < 8; i += 2)
    if(!(n % i))
        printf("%d ",i); 
    return 0;
}
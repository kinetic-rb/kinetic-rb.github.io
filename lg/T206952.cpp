//cowfind
#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

ll js, ans, js1, f, wz;
string s;

int main(){
//\tfreopen("cowfind.in", "r", stdin);
//\tfreopen("cowfind.out", "w", stdout);
\tcin >> s;
\tfor(int i = 0; i < s.size(); i++){
\t\tif(s[i] == '('){
\t\t\twz = i;
\t\t\tbreak;
\t\t}
\t}
\tfor(int i = 0; i < s.size(); i++){
\t\tif(s[i] == '('){
\t\t\tif(i == wz){
\t\t\t\tjs++;
\t\t\t}
\t\t\tif(s[i + 1] == '('){
\t\t\t\tjs++; 
\t\t\t}
\t\t\tjs1 = 0;
\t\t}
\t\telse{
\t\t\tjs1++;
\t\t\tif(js >= 2 && js1 >= 2){
\t\t\t\tans += (js - 1);
\t\t\t}
\t\t}
\t}
\tcout << ans;
\treturn 0;
}
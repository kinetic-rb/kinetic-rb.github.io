#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
struct node{
    int id;
    char bracket;
};
stack<node> stk;
char bracket;
int i;
int ansbegin=-999999;
int anslen=0;
int ansend=-999999;
int sanslen;
char str[1200001];
bool vis[1200001];
inline bool matching(node ca,node cb){
    if(ca.bracket==')')return cb.bracket=='(';
    if(ca.bracket==']')return cb.bracket=='[';
    return false;
}
inline int __max(int a,int b){
    return a>b?a:b;
}
inline void Find_LongestRegular(){
    int ansid=0, len = strlen(str);
    for(i=0;i<len;++i)
    {
        if(!vis[i]){
            sanslen=0;
            ansid=i+1;
        }
        else{
            sanslen++;
            if(sanslen>anslen){
                ansbegin=ansid;
                ansend=i;
                anslen=sanslen;
            }
        }
    }
}
int main()
{
    int match=0, len;
    scanf("%s",&str);
    len = strlen(str);
    for(i=0;i<len;++i)
    {
        bracket=str[i];
        node b;
        b.bracket=bracket;
        b.id=i;
        stk.push(b);
        //stk.ergodic();
        if(bracket==')'||bracket==']'){
            if(stk.size()==1){
                continue;
            }
            stk.pop();
            node top=stk.top();
            stk.push(b);
            if(matching(b,top)){
                match++;
                stk.pop();
                stk.pop();
                vis[b.id]=true;
                vis[top.id]=true;

            }
        }
    }
    Find_LongestRegular();
    for(i=ansbegin;i<=ansend;++i)
    {
        putchar(str[i]);
    }
    return 0;
}

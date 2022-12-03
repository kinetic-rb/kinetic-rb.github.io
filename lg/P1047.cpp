#include<iostream>
using namespace std;
int main()
{
    int L,M,i,j;
    int section[10001]= {0};
    int a,b,tree_sum=0,tree_ex,tree_new;
 
    cin>>L>>M;//\u8f93\u5165\u9a6c\u8def\u957f\u5ea6\u4e0e\u533a\u57df\u6570\u76ee
 
    for (i=0; i<M; i++)
    {
        cin>>a>>b;//\u8f93\u5165\u8d77\u59cb\u70b9\u4e0e\u7ec8\u6b62\u70b9
        for(j=a; j<=b; j++) //\u4ee4\u8303\u56f4\u5185\u7684\u6811\u79fb\u8d70
            section[j]=1;
    }
 
    for(i=0; i<=L; i++) //\u7edf\u8ba1\u9a6c\u8def\u957f\u5ea6\u5185\u88ab\u79fb\u8d70\u7684\u6811\u7684\u6570\u76ee
        if(section[i]==1)
            tree_sum++;
 
    tree_ex=L+1;//\u539f\u6765\u7684\u6811\u7684\u6570\u76ee
    tree_new=tree_ex-tree_sum;//\u79fb\u8d70\u540e\u7684\u6811\u7684\u6570\u76ee
 
    cout<<tree_new<<endl;
 
    return 0;
}
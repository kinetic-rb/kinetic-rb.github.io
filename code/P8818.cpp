#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
struct node{
  int l,r,mini,maxn,miniz,maxnf;
  bool b,bb,bbb;
}aa[400005],bb[400005];
void build(int x,int l,int r){
  aa[x].l=l,aa[x].r= r;
  aa[x].mini=2e9,aa[x].maxn = -2e9;
  aa[x].miniz=2e9,aa[x].maxnf = -2e9;
  if(l==r){
    aa[x].mini=a[l];
    aa[x].maxn=a[l];
    if(a[l]==0){
      aa[x].bbb=1;
    }else if(a[l]>0){
      aa[x].b=1;  
      aa[x].miniz=a[l];
    }else{
      aa[x].bb=1;
      aa[x].maxnf = a[l];
    }
    return;
  }
  int mid = (l+r)/2;
  build(x*2,l,mid);
  build(x*2+1,mid+1,r);
  aa[x].mini=min(aa[x*2].mini,aa[x*2+1].mini);
  aa[x].maxn=max(aa[x*2].maxn,aa[x*2+1].maxn);
  aa[x].miniz=min(aa[x*2].miniz,aa[x*2+1].miniz);
  aa[x].maxnf=max(aa[x*2].maxnf,aa[x*2+1].maxnf);
  if(aa[x*2].b==1||aa[x*2+1].b==1){
    aa[x].b = 1;
  }
  if(aa[x*2].bb==1||aa[x*2+1].bb==1){
    aa[x].bb = 1;
  }
  if(aa[x*2].bbb==1||aa[x*2+1].bbb==1){
    aa[x].bbb = 1;
  }
  return;
}
void Build(int x,int l,int r){
  bb[x].l=l,bb[x].r= r;
  bb[x].mini=2e9,bb[x].maxn = -2e9;
  bb[x].miniz=2e9,bb[x].maxnf = -2e9;
  if(l==r){
    bb[x].mini=b[l];
    bb[x].maxn=b[l];
    if(b[l]==0){
      bb[x].bbb=1;
    }else if(b[l]>0){
      bb[x].b=1;  
      bb[x].miniz=b[l];
    }else{
      bb[x].bb=1;
      bb[x].maxnf = b[l];
    }
    return;
  }
  int mid = (l+r)/2;
  Build(x*2,l,mid);
  Build(x*2+1,mid+1,r);
  bb[x].mini=min(bb[x*2].mini,bb[x*2+1].mini);
  bb[x].maxn=max(bb[x*2].maxn,bb[x*2+1].maxn);
  bb[x].miniz=min(bb[x*2].miniz,bb[x*2+1].miniz);
  bb[x].maxnf=max(bb[x*2].maxnf,bb[x*2+1].maxnf);
  if(bb[x*2].b==1||bb[x*2+1].b==1){
    bb[x].b = 1;
  }
  if(bb[x*2].bb==1||bb[x*2+1].bb==1){
    bb[x].bb = 1;
  }
  if(bb[x*2].bbb==1||bb[x*2+1].bbb==1){
    bb[x].bbb = 1;
  }
  return;
}
node query(int x,int l,int r){
  if(l<=aa[x].l&&r>=aa[x].r){
    return aa[x];
  }
  int mid = (aa[x].l+aa[x].r)/2;
  node u,s;
  u.mini = 2e9,u.maxn = -2e9;
  u.miniz = 2e9,u.maxnf = -2e9;
  u.b = u.bb = u.bbb = 0;
  if(mid>=l){
    s = query(x*2,l,r);
    if(s.b==1){
      u.b=1;
    }
    if(s.bb == 1){
      u.bb=1;
    }
    if(s.bbb == 1){
      u.bbb=1;
    }
    u.mini=min(u.mini,s.mini);
    u.maxn=max(u.maxn,s.maxn);
    u.miniz=min(u.miniz,s.miniz);
    u.maxnf=max(u.maxnf,s.maxnf);
  }
  if(mid+1<=r){
    s = query(x*2+1,l,r);
    if(s.b==1){
      u.b=1;
    }
    if(s.bb == 1){
      u.bb=1;
    }
    if(s.bbb == 1){
      u.bbb=1;
    }
    u.mini=min(u.mini,s.mini);
    u.maxn=max(u.maxn,s.maxn);
    u.miniz=min(u.miniz,s.miniz);
    u.maxnf=max(u.maxnf,s.maxnf);
  }
  //cout << x<< " "<< aa[x].l<< " "<< aa[x].r << " "<< l<< " "<< r<<" " << u.b <<" "<<u.bb <<" "<<u.bbb <<endl;
  return u;
}
node Query(int x,int l,int r){
  if(l<=bb[x].l&&r>=bb[x].r){
    return bb[x];
  }
  int mid = (bb[x].l+bb[x].r)/2;
  node u,s;
  u.mini = 2e9,u.maxn = -2e9;
  u.miniz = 2e9,u.maxnf = -2e9;
  u.b = u.bb = u.bbb = 0;
  if(mid>=l){
    s = Query(x*2,l,r);
    if(s.b==1){
      u.b=1;
    }
    if(s.bb == 1){
      u.bb=1;
    }
    if(s.bbb == 1){
      u.bbb=1;
    }
    u.mini=min(u.mini,s.mini);
    u.maxn=max(u.maxn,s.maxn);
    u.miniz=min(u.miniz,s.miniz);
    u.maxnf=max(u.maxnf,s.maxnf);
  }
  if(mid+1<=r){
    s = Query(x*2+1,l,r);
    if(s.b==1){
      u.b=1;
    }
    if(s.bb == 1){
      u.bb=1;
    }
    if(s.bbb == 1){
      u.bbb=1;
    }
    u.mini=min(u.mini,s.mini);
    u.maxn=max(u.maxn,s.maxn);
    u.miniz=min(u.miniz,s.miniz);
    u.maxnf=max(u.maxnf,s.maxnf);
  }
  //cout << x<< " "<< bb[x].l<< " "<< bb[x].r << " "<< l<< " "<< r<<" " << u.b <<" "<<u.bb <<" "<<u.bbb <<endl;
  return u;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  int n,m,t;
  cin>> n >> m >> t;
  for(int i = 1;i <= n;i++){
    cin >>a[i];
  } 
  for (int j = 1; j <= m;j++){
    cin >> b[j];
  }
  build(1,1,n);
  Build(1,1,m);
  while(t--){
    int x,y,xx,yy;
    cin >> x >> y >> xx >> yy;
    node i = query(1,x,y),j=Query(1,xx,yy);
    //cout << i.mini <<" "<<i.maxn <<" "<<i.b<< " "<< i.bb << " "<<i.bbb << " "<< i.miniz<< " "<<i.maxnf<< endl;
    //cout << j.mini <<" "<<j.maxn <<" "<<j.b<< " "<< j.bb << " "<<j.bbb << " "<< j.miniz<< " "<<j.maxnf<< endl;
    long long maxn = -2e18;
    if(i.b==1){
      if(j.bb == 0){
        long long e = i.maxn,u = j.mini;
        //cout << e <<" "<< u << endl;
        maxn = max(maxn,e*u);
      }else{
        long long e = i.miniz,u = j.mini;
        //cout << e <<" "<< u << endl;
        maxn = max(maxn,e*u);
      }
    }
    if(i.bb==1){
      if(j.b == 0){
        long long e = i.mini,u = j.maxn;
        maxn = max(maxn,e*u);
        //cout << e <<" "<< u << endl;
      }else{
        long long e = i.maxnf,u = j.maxn;
        //cout << e <<" "<< u << endl;
        maxn = max(maxn,e*u);
      }
    }
    if(i.bbb==1){
      maxn=max(maxn,(long long)0);
    }
    cout << maxn << endl;
  }
} 

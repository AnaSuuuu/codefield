#include<bits/stdc++.h>
using namespace std;
const ll N=1e4+5;
ll fa[N];
inline ll get_fa(ll x){
  return (x==fa[x])?x:(fa[x]=get_fa(fa[x]));
}
ll main(){
  freopen("3367.in","r",stdin);
  freopen("3367.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++){
    ll op,x,y;
    cin>>op>>x>>y;
    ll fx=get_fa(x),fy=get_fa(y);
    switch(op){
      case 1:{
        fa[fx]=fy;
        break;
      }
      case 2:{
        if(fx==fy)puts("Y");
        else puts("N");
        break;
      }
    }
  }
  return 0;
}
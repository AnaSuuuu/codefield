#include<bits/stdc++.h>
using namespace std;
const ll N=3e5+5;
ll fa[N],dis[N],num[N];//num[i]以i为开头的队列长度，dis[i]i距离i所在队列开头的长度
ll get_fa(ll x){
  if(x==fa[x])return x;
  ll fx=get_fa(fa[x]);
  dis[x]+=dis[fa[x]];
  return fa[x]=fx;
}
void Merge(ll x,ll y){
  ll fx=get_fa(x),fy=get_fa(y);
  fa[fx]=fy;
  dis[fx]+=num[fy];
  num[fy]+=num[fx];
  num[fx]=0;
  return ;
}
ll main(){
  freopen("1196.in","r",stdin);
  freopen("1196.out","w",stdout);
  ll t;
  cin>>t;
  for(ll i=1;i<=3e5;i++){
    fa[i]=i;
    num[i]=1;
    dis[i]=0;
  }
  while(t--){
    char op;
    cin>>op;
    switch(op){
      case 'M':{
        ll x,y;
        cin>>x>>y;
        Merge(x,y);
        break;
      }
      case 'C':{
        ll x,y;
        cin>>x>>y;
        ll fx=get_fa(x),fy=get_fa(y);
        if(fx!=fy)puts("-1");
        else cout<<abs(dis[x]-dis[y])-1<<endl;
        break;
      }
    }
  }
  //cout<<dis[2]<<' '<<dis[4]<<endl;
  return 0;
}
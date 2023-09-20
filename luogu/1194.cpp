#include<bits/stdc++.h>
using namespace std;
const ll N=3e6+5;
ll tot,fa[505];
ll a[505][505];
struct Edge{
  ll u,v,w;
}e[N];
ll get_fa(ll x){
  if(x==fa[x])return x;
  return fa[x]=get_fa(fa[x]);
}
bool cmp(Edge x,Edge y){
  return x.w<y.w;
}
ll main(){
  freopen("1194.in","r",stdin);
  freopen("1194.out","w",stdout);
  ll a0,n;
  scanf("%d%d",&a0,&n);
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++){
      scanf("%d",&e[++tot].w);
      if(e[tot].w==0)e[tot].w=a0;
      e[tot].u=i,e[tot].v=j;
    }
  for(ll i=1;i<=n;i++){
    e[++tot].w=a0;
    e[tot].v=0,e[tot].u=i;
  }
  for(ll i=0;i<=n;i++)fa[i]=i;
  sort(e+1,e+1+tot,cmp);
  ll ans=0;
  for(ll i=1;i<=tot;i++){
    ll u0=get_fa(e[i].u),v0=get_fa(e[i].v);
    if(u0==v0)continue;
    ans+=e[i].w;
    fa[u0]=v0;
  }
  prllf("%d\n",ans);
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
ll x[N],y[N],fa[N];
inline ll get_fa(ll x){
  return x==fa[x]?x:(fa[x]=get_fa(fa[x]));
}
struct Edge{
  ll u,v;
  double dis;
}e[N*N];
bool cmp(Edge x,Edge y){
  return x.dis<y.dis;
}
ll main(){
  freopen("2872.in","r",stdin);
  freopen("2872.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    cin>>x[i]>>y[i];
  }
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++){
    ll u,v;
    cin>>u>>v;
    ll fu=get_fa(u),fv=get_fa(v);
    if(fu==fv)continue;
    fa[fu]=fv;
  }
  ll tot=0;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      if(get_fa(i)==get_fa(j))continue;
      e[++tot].u=i;
      e[tot].v=j;
      e[tot].dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
  }
  double ans=0;
  sort(e+1,e+1+tot,cmp);
  for(ll i=1;i<=tot;i++){
    ll fu=get_fa(e[i].u),fv=get_fa(e[i].v);
    if(fu==fv)continue;
    //cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].dis<<endl;;
    ans+=e[i].dis;
    fa[fu]=fv;
  }
  prllf("%.2lf\n",ans);
  return 0;
}
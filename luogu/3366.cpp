#include<bits/stdc++.h>
using namespace std;
const ll N=2e5+5;
struct Edge{
  ll u,v,w;
}e[N];
ll fa[N];
bool cmp(Edge x,Edge y){
  return x.w<y.w;
}
inline ll get_fa(ll x){
  return x==fa[x]?x:(fa[x]=get_fa(fa[x]));
}
ll main(){
  freopen("3366.in","r",stdin);
  freopen("3366.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=m;i++){
    cin>>e[i].u>>e[i].v>>e[i].w;
  }
  ll ans=0;
  sort(e+1,e+1+m,cmp);
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++){
    ll fu=get_fa(e[i].u),fv=get_fa(e[i].v);
    if(fu==fv)continue;
    fa[fu]=fv;
    ans+=e[i].w;
  }
  for(ll i=2;i<=n;i++){
    if(get_fa(i)!=get_fa(i-1)){
      puts("orz");
      return 0;
    }
  }
  cout<<ans<<endl;
  return 0;
}
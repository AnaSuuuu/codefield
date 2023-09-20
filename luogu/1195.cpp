#include<bits/stdc++.h>
using namespace std;
const ll N=1e4+5;
struct Edge{
  ll u,v,w;
}e[N];
ll co[N],fa[N];
ll get_fa(ll x){
  if(fa[x]==x)return x;
  return fa[x]=get_fa(fa[x]);
}
bool cmp(Edge x,Edge y){
  return x.w<y.w;
}
ll cnt[N];
ll main(){
  freopen("1195.in","r",stdin);
  freopen("1195.out","w",stdout);
  ll n,m,k,ans=0,cnt;
  scanf("%d%d%d",&n,&m,&k);cnt=n;
  for(ll i=1;i<=m;i++)
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
  for(ll i=1;i<=n;i++)fa[i]=i;
  sort(e+1,e+1+m,cmp);
  for(ll i=1;i<=m;i++){
    ll u0=get_fa(e[i].u),v0=get_fa(e[i].v);
    if(u0==v0)continue;
    if(cnt==k)break;
    fa[u0]=v0;
    cnt--;ans+=e[i].w;
  }
  //for(ll i=1;i<=n;i++)cout<<fa[i]<<' ';
  //cout<<endl;
  if(cnt>k)puts("No Answer");
  else prllf("%d\n",ans);
  return 0;
}
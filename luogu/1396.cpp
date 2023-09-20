#include<bits/stdc++.h>
using namespace std;
const ll N=2e4+6;
struct Edge{
  ll u,v,w;
}e[N];
ll n,m,s,t,fa[N];
ll get_fa(ll x){
  if(fa[x]==x)return x;
  return fa[x]=get_fa(fa[x]);
}
bool kruskal(ll lim){
  for(ll i=1;i<=m;i++){
    if(e[i].w<=lim)
      fa[get_fa(e[i].u)]=get_fa(e[i].v);
    else break;
  }
  if(get_fa(s)==get_fa(t))return true;
  else return false;
}
bool cmp(Edge x,Edge y){
  return x.w<y.w;
}
ll main(){
  freopen("1396.in","r",stdin);
  freopen("1396.out","w",stdout);
  ll r=0,l=0x3f3f3f3f;
  scanf("%d%d%d%d",&n,&m,&s,&t);
  for(ll i=1;i<=m;i++){
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    l=min(l,e[i].w);
    r=max(r,e[i].w);
  }
  sort(e+1,e+1+m,cmp);
  ll ans;
  //cout<<kruskal(3)<<endl;
  while(l<=r){
    ll mid=(l+r)>>1;
    for(ll i=1;i<=n;i++)fa[i]=i;
    if(kruskal(mid)){
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
  }
  prllf("%d\n",ans);
  return 0;
}

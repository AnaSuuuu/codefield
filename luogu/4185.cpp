#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
struct Edge{
  ll u,v,w;
}e[N];
struct Node{
  ll k,v,id,ans;
}s[N];
ll fa[N],cnt[N];
bool cmp0(Edge x,Edge y){
  return x.w>y.w;
}
bool cmp1(Node x,Node y){
  return x.k>y.k;
}
bool cmp2(Node x,Node y){
  return x.id<y.id;
}
inline ll get_fa(ll x){
  return (x==fa[x])?x:(fa[x]=get_fa(fa[x]));
}
ll main(){
  freopen("4185.in","r",stdin);
  freopen("4185.out","w",stdout);
  ll n,q;
  cin>>n>>q;
  for(ll i=1;i<n;i++)
    cin>>e[i].u>>e[i].v>>e[i].w;
  sort(e+1,e+n,cmp0);
  for(ll i=1;i<=q;i++){
    cin>>s[i].k>>s[i].v;
    s[i].id=i;
  }
  sort(s+1,s+1+q,cmp1);
  for(ll i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
  ll cur=1;
  for(ll i=1;i<=q;i++){
    for(;e[cur].w>=s[i].k&&cur<=n;cur++){
      ll u=e[cur].u,v=e[cur].v;
      ll fu=get_fa(u),fv=get_fa(v);
      //if(fu==fv)continue;
      cnt[fu]+=cnt[fv];
      fa[fv]=fu;
    }
    s[i].ans=cnt[get_fa(s[i].v)];
  }
  sort(s+1,s+1+q,cmp2);
  for(ll i=1;i<=q;i++)cout<<s[i].ans-1<<endl;
  return 0;
}
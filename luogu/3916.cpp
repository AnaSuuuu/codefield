#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
ll head[N],tot;
struct Edge{
  ll _to,_next;
}e[N];
bool vis[N];
ll a[N];
void add_edge(ll u,ll v){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  head[u]=tot;
}
void dfs(ll u,ll maxm){
  vis[u]=1;
  a[u]=max(a[u],maxm);
  for(ll i=head[u];i;i=e[i]._next){
    ll v=e[i]._to;
    if(vis[v])continue;
    dfs(v,maxm);
  }
}
ll main(){
  freopen("3916.in","r",stdin);
  freopen("3916.out","w",stdout);
  ll n,m;
  scanf("%d%d",&n,&m);
  for(ll i=1;i<=m;i++){
    ll u,v;
    scanf("%d%d",&u,&v);
    add_edge(v,u);
  }
  for(ll i=n;i>=1;i--)dfs(i,i);
  for(ll i=1;i<=n;i++)prllf("%d ",a[i]);
  return 0;
}
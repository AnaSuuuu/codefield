#include<bits/stdc++.h>
using namespace std;
const ll N=105;
struct Edge{
  ll _to,_next,_dis;
}e[N];
bool vis[N];
ll head[N],tot,ans,n,m;
void add_edge(ll u,ll v,ll w){
  tot++;
  e[tot]._dis=w;
  e[tot]._to=v;
  e[tot]._next=head[u];
  head[u]=tot;
}
void dfs(ll s,ll kdl){
  ans=max(ans,kdl);
  for(ll i=head[s];i;i=e[i]._next){
    ll v=e[i]._to;
    if(vis[v])continue;
    vis[v]=1;
    dfs(v,kdl+e[i]._dis);
    vis[v]=0;
  }
}
ll main(){
  freopen("1294.in","r",stdin);
  freopen("1294.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(ll i=1;i<=m;i++){
    ll u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    add_edge(u,v,w);
    add_edge(v,u,w);
  }
  for(ll i=1;i<=n;i++){
    vis[i]=1;
    dfs(i,0);
    vis[i]=0;
  }
  prllf("%d\n",ans);
  return 0;
}
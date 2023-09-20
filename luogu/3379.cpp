#include<bits/stdc++.h>
using namespace std;
const ll N=5e5+5;
ll head[N],tot;
ll fa[N][30],dep[N];
struct Edge{
  ll _to,_next;
}e[N<<1];
void add_edge(ll u,ll v){
  tot++;
  e[tot]._next=head[u];
  e[tot]._to=v;
  head[u]=tot;
}
void dfs(ll u,ll f){
  for(ll i=head[u];i;i=e[i]._next){
    ll v=e[i]._to;
    if(v==f)continue;
    fa[v][0]=u;
    dep[v]=dep[u]+1;
    dfs(v,u);
  }
}
ll lca(ll x,ll y){
  if(dep[x]<dep[y])swap(x,y);
  for(ll i=25;i>=0;i--){
    if(dep[fa[x][i]]>=dep[y])
      x=fa[x][i];
  }
  if(x==y)return x;
  //puts("AAA");
  for(ll i=25;i>=0;i--){
    if(fa[x][i]!=fa[y][i]){
      x=fa[x][i];
      y=fa[y][i];
    }
  }
  return fa[x][0];
}
ll main(){
  freopen("3379.in","r",stdin);
  freopen("3379.out","w",stdout);
  ll n,m,s;
  cin>>n>>m>>s;
  for(ll i=1;i<n;i++){
    ll u,v;
    cin>>u>>v;
    add_edge(u,v);
    add_edge(v,u);
  }
  dfs(s,s);
  fa[s][0]=s;
  for(ll i=1;i<=25;i++){
    for(ll j=1;j<=n;j++)
      fa[j][i]=fa[fa[j][i-1]][i-1];
  }
  for(ll i=1;i<=m;i++){
    ll x,y;
    cin>>x>>y;
    cout<<lca(x,y)<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=2e5+5;
ll head[N],tot;
ll dep[N],fa[N][25];
struct Edge{
  ll _to,_next;
}e[N];
void add_edge(ll u,ll v){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  head[u]=tot;
}
void pre_dep(ll u,ll f){
  dep[u]=dep[f]+1;
  fa[u][0]=f;
  for(ll i=0;i<=19;i++)fa[u][i+1]=fa[fa[u][i]][i];
  for(ll i=head[u];i;i=e[i]._next){
    ll v=e[i]._to;
    if(v==f)continue;
    pre_dep(v,u);
  }
}
ll Lca(ll x,ll y){
  if(dep[x]<dep[y])x^=y^=x^=y;
  for(ll i=20;i>=0;i--){
    if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
  }
  if(x==y)return x;
  for(ll i=20;i>=0;i--){
    if(fa[x][i]!=fa[y][i]){
      x=fa[x][i];
      y=fa[y][i];
    }
  }
  return fa[x][0];
}
void query(ll x,ll y){
  prllf("%d\n",dep[x]+dep[y]-dep[Lca(x,y)]*2);
  return ;
}
ll main(){
  freopen("#10130.in","r",stdin);
  freopen("#10130.out","w",stdout);
  ll n;
  scanf("%d",&n);
  for(ll i=1;i<n;i++){
    ll u,v;
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }
  pre_dep(1,0);
  ll q;
  //for(ll i=1;i<=n;i++)cout<<fa[i][0]<<' ';
  //cout<<endl;
  //cout<<Lca(1,2)<<endl;
  scanf("%d",&q);
  for(ll i=1;i<=q;i++){
    ll x,y;
    scanf("%d%d",&x,&y);
    query(x,y);
  }
  
  return 0;
}
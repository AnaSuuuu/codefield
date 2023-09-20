#include<bits/stdc++.h>
using namespace std;
const ll N=5e4+5;
inline void in(ll &x){
  x=0;
  ll f=1;
  char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=f;
}
ll n,m,q,dis[N][25],Fa[N][25];
ll dep[N];
struct Edge{
  ll u,v,w;
}e0[N];
struct edge{
  ll _to,_next,_dis;
}e[N*2];
struct Node{
  ll x,y;
  ll head,next;
}s[N];
ll fa[N],ans[N],tot;
ll head[N],vis[N];
inline ll get_fa(ll x){
  return x==fa[x]?x:(fa[x]=get_fa(fa[x]));
}
bool cmp(Edge x,Edge y){
  return x.w>y.w;
}
void add_edge(ll u,ll v,ll w){
  tot++;
  e[tot]._next=head[u];
  e[tot]._to=v;
  e[tot]._dis=w;
  head[u]=tot;
}
void kruscal(){
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++){
    ll fu=get_fa(e0[i].u),fv=get_fa(e0[i].v);
    if(fu==fv)continue;
    fa[fu]=fv;
    add_edge(e0[i].u,e0[i].v,e0[i].w);
    add_edge(e0[i].v,e0[i].u,e0[i].w);
  }
}
void dfs(ll u,ll f){
  vis[u]=1;
  for(ll i=head[u];i;i=e[i]._next){
    ll v=e[i]._to;
    if(v==f)continue;
    dis[v][0]=e[i]._dis;
    Fa[v][0]=u;
    dep[v]=dep[u]+1;
    dfs(v,u);
  }
}
inline ll lca(ll x,ll y){
  ll ans=0x3f3f3f3f;
  ll fx=get_fa(x),fy=get_fa(y);
  if(fx!=fy)return -1;
  if(dep[x]<dep[y])swap(x,y);
  for(ll i=20;i>=0;i--){
    if(dep[Fa[x][i]]>=dep[y]){
      ans=min(ans,dis[x][i]);
      x=Fa[x][i];
    }
  }
  if(x==y)return ans;
  for(ll i=20;i>=0;i--){
    if(Fa[x][i]!=Fa[y][i]){
      ans=min(ans,min(dis[x][i],dis[y][i]));
      x=Fa[x][i];
      y=Fa[y][i];
    }
  }
  ans=min(ans,min(dis[x][0],dis[y][0]));
  return ans;
}
ll main(){
  freopen("1967.in","r",stdin);
  freopen("1967.out","w",stdout);
  in(n);in(m);
  memset(dis,0x3f,sizeof(dis));
  for(ll i=1;i<=m;i++){
    in(e0[i].u);in(e0[i].v);in(e0[i].w);
  }
  sort(e0+1,e0+1+m,cmp);
  kruscal();
  for(ll i=1;i<=n;i++)
    if(vis[i]==0){
      dfs(i,i);
      Fa[i][0]=i;
    }
  for(ll i=1;i<=20;i++){
    for(ll j=1;j<=n;j++){
      Fa[j][i]=Fa[Fa[j][i-1]][i-1];
    }
  }
  for(ll i=1;i<=20;i++){
    for(ll j=1;j<=n;j++){
      dis[j][i]=min(dis[j][i-1],dis[Fa[j][i-1]][i-1]);
    }
  }
  ll q;
  in(q);
  for(ll i=1;i<=q;i++){
    ll x,y;
    in(x);in(y);
    prllf("%d\n",lca(x,y));;
  }
  return 0;
}
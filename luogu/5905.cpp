#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
struct Edge{
  ll _to,_next,_dis;
}e[N];
struct Node{
  ll dis,u;
  const bool operator <(const Node &x) const {
    return x.dis<dis;
  }
};
ll head[N],tot,dis[N];
ll cnt[N],n,m;
ll h[N];
ll ans[N];
bool vis[N];
void add_edge(ll u,ll v,ll w){
  tot++;
  e[tot]._to=v;
  e[tot]._next=head[u];
  e[tot]._dis=w;
  head[u]=tot;
}
bool spfa(ll s){
  queue<ll>q;
  q.push(s);
  memset(h,0x3f,sizeof(h));
  h[s]=0;cnt[s]=1;vis[s]=1;
  while(q.size()){
    ll u=q.front();
    q.pop();
    vis[u]=0;
    for(ll i=head[u];i;i=e[i]._next){
      ll v=e[i]._to;
      if(h[v]>h[u]+e[i]._dis){
        h[v]=h[u]+e[i]._dis;
        if(vis[v]==0){
          q.push(v);
          vis[v]=1;
          cnt[v]++;
          if(cnt[v]==n+1)return false;
        }
      }
    }
  }
  return true;
}
void dij(ll s){
  priority_queue<Node> q;
  for(ll i=1;i<=n;i++)dis[i]=1e9;
  memset(vis,0,sizeof(vis));
  dis[s]=0;
  q.push(Node{0,s});
  while(q.size()){
    Node tmp=q.top();
    q.pop();
    ll u=tmp.u;
    if(vis[u])continue;
    vis[u]=1;
    for(ll i=head[u];i;i=e[i]._next){
      ll v=e[i]._to;
      if(dis[v]>dis[u]+(h[u]+e[i]._dis-h[v])){
        dis[v]=dis[u]+(h[u]+e[i]._dis-h[v]);
        
        if(!vis[v]) q.push(Node{dis[v],v});
      }
    }
  }
}
ll main(){
  freopen("5905.in","r",stdin);
  freopen("5905.out","w",stdout);
  cin>>n>>m;
  for(ll i=1;i<=m;i++){
    ll u,v,w;
    cin>>u>>v>>w;
    add_edge(u,v,w);
  }
  for(ll i=1;i<=n;i++){
    add_edge(0,i,0);
  }
  if(spfa(0)==false){
    puts("-1");
    return 0;
  }
  //for(ll i=1;i<=n;i++)cout<<h[i]<<endl;
  for(ll i=1;i<=n;i++){
    dij(i);
    for(ll j=1;j<=n;j++)
      ans[i]+=1ll*j*(dis[j]==1e9?1e9:(dis[j]+h[j]-h[i]));
    //for(ll j=1;j<=n;j++)cout<<dis[j]+h[j]-h[i]<<' ';
    //puts("");
  }
  for(ll i=1;i<=n;i++)cout<<ans[i]<<endl;
  return 0;
}
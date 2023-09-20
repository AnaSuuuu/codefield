#include<bits/stdc++.h>
using namespace std;
const ll N=5e5+5;
ll n,m,b,ans=-1,f[N];
ll tot,head[N];
ll vis[N],dis[N];
struct Edge{
  ll _to,_next,_dis;
}e[N];
struct Node{
  ll u,dis;
  bool operator < (const Node &a) const {
    return a.dis<dis;
  }
};
void add_edge(ll u,ll v,ll dis){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  e[tot]._dis=dis;
  head[u]=tot;
}
bool judge(ll lim){
  priority_queue<Node>q;
  q.push(Node{1,0});
  memset(vis,0,sizeof(vis));
  memset(dis,0x3f,sizeof(dis));
  dis[1]=0;
  while(q.size()){
    Node tmp=q.top();
    q.pop();
    ll u=tmp.u;
    if(vis[u])continue;
    vis[u]=1;
    for(ll i=head[u];i;i=e[i]._next){
      ll v=e[i]._to;
      if(f[v]>lim)continue;
      if(dis[v]>dis[u]+e[i]._dis){
        dis[v]=dis[u]+e[i]._dis;
        if(vis[v]==0)q.push((Node){v,dis[v]});
      }
    }
  }
  return dis[n]<=b;
}
ll main(){
  freopen("1462.in","r",stdin);
  freopen("1462.out","w",stdout);
  cin>>n>>m>>b;
  ll r=0,l=0;
  for(ll i=1;i<=n;i++)cin>>f[i],r=max(r,f[i]);
  l=max(f[1],f[n]);
  for(ll i=1;i<=m;i++){
    ll u,v,w;
    cin>>u>>v>>w;
    add_edge(u,v,w);
    add_edge(v,u,w);
  }
  while(r>=l){
    ll mid=(r+l)>>1;
    if(judge(mid)){
      r=mid-1;
      ans=mid;
    }
    else l=mid+1;
  }
  if(ans==-1)puts("AFK");
  else cout<<ans<<endl;
  return 0;
}
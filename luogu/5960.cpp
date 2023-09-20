#include<bits/stdc++.h>
using namespace std;
const ll N=2e4+5;
struct Edge{
  ll _to,_next,_dis;
}e[N];
ll vis[N],dis[N],n;
ll head[N],tot,cnt[N];
bool ok=1;
void add_edge(ll u,ll v,ll w){
  tot++;
  e[tot]._to=v;
  e[tot]._next=head[u];
  e[tot]._dis=w;
  head[u]=tot;
}
void spfa(){
  queue<ll> q;
  memset(dis,0x3f,sizeof(dis));
  q.push(0);
  dis[0]=0;
  vis[0]=1;
  while(q.size()){
    ll u=q.front();
    q.pop();
    vis[u]=0;
    for(ll i=head[u];i;i=e[i]._next){
      ll v=e[i]._to;
      if(dis[v]>dis[u]+e[i]._dis){
        dis[v]=dis[u]+e[i]._dis;
        if(vis[v]==0){
          q.push(v);
          vis[v]=1;
          cnt[v]++;
        }
      }
      if(cnt[v]==n+1){
        puts("NO");
        ok=0;
        return ;
      }
    }
  }
}
ll main(){
  freopen("5960.in","r",stdin);
  freopen("5960.out","w",stdout);
  ll m;
  scanf("%d%d",&n,&m);
  for(ll i=1;i<=m;i++){
    ll x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    add_edge(y,x,z);
  }
  for(ll i=1;i<=n;i++)
    add_edge(0,i,0);
  spfa();
  if(ok){
    for(ll i=1;i<=n;i++)cout<<dis[i]<<' ';
  }
  return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
struct Edge{
  ll _to,_next,_dis;
}e[N];
ll tot,head[N],n,ok;
ll dis[N],vis[N],cnt[N];
void add_edge(ll u,ll v,ll w){
  e[++tot]._next=head[u];
  e[tot]._to=v;
  e[tot]._dis=w;
  head[u]=tot;
}
void spfa(ll s){
  queue<ll> q;
  q.push(s);
  memset(dis,0x3f,sizeof(dis));
  dis[s]=0;
  while(q.size()){
    ll u=q.front();
    q.pop();
    vis[u]=0;
    for(ll i=head[u];i;i=e[i]._next){
      ll v=e[i]._to;
      if(dis[v]>dis[u]+e[i]._dis){
        dis[v]=dis[u]+e[i]._dis;
        if(!vis[v])q.push(v),cnt[v]++;
        vis[v]=1;
      }
      if(cnt[v]==n+1){
        ok=0;
        return ;
      }
    }
  }
}
ll main(){
  freopen("3275.in","r",stdin);
  freopen("3275.out","w",stdout);
  ll k;
  scanf("%lld%lld",&n,&k);
  for(ll i=1;i<=k;i++){
    ll x,a,b;
    ok=1;
    scanf("%lld%lld%lld",&x,&a,&b);
    switch(x){
      case 1:{
        add_edge(a,b,0);
        add_edge(b,a,0);
        break;
      }
      case 2:{
        add_edge(b,a,-1);
        break;
      }
      case 3:{
        add_edge(a,b,0);
        break;
      }
      case 4:{
        add_edge(a,b,-1);
        break;
      }
      case 5:{
        add_edge(b,a,0);
        break;
      }
    }  
  }
  for(ll i=1;i<=n;i++)add_edge(0,i,0);
  spfa(0);
  ll ans=0;
  if(ok==0){
    puts("-1");
    return 0;
  }
  ll minn=1;
  for(ll i=1;i<=n;i++)minn=min(minn,dis[i]);
  if(minn<=0)minn=-minn+1;
  for(ll i=1;i<=n;i++)ans+=dis[i];
  prllf("%lld\n",ans+1ll*n*minn);
  return 0;
}
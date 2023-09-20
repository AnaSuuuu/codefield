#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e6+5;
const ll mod=100003;
ll head[N],tot;
ll dis[N];
ll cnt[N];
bool vis[N];
struct Edge{
  ll _to,_next;
}e[N];
void add_edge(ll u,ll v){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  head[u]=tot;
}
struct Node{
  ll u,dis;
};
ll main(){
  freopen("1144.in","r",stdin);
  freopen("1144.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=m;i++){
    ll x,y;
    cin>>x>>y;
    add_edge(x,y);
    add_edge(y,x);
  }
  queue<ll>q;
  q.push(1);
  memset(dis,0x3f,sizeof(dis));
  dis[1]=0;cnt[1]=1;
  vis[1]=1;
  while(q.size()){
    ll u=q.front();
    q.pop();
    vis[u]=0;
    for(ll i=head[u];i;i=e[i]._next){
      ll v=e[i]._to;
      if(dis[v]>=dis[u]+1){
        if(dis[v]==dis[u]+1)cnt[v]=(cnt[v]+cnt[u])%mod;
        else {
          cnt[v]=cnt[u];
          dis[v]=dis[u]+1;
          if(vis[v]==0)q.push(v),vis[v]=1;
        }
      }
    }
  }
  for(ll i=1;i<=n;i++)cout<<cnt[i]%mod<<endl;
  return 0;
}
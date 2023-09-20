#include<bits/stdc++.h>
using namespace std;
const ll N=4e5+5;
struct Edge{
  ll _to,_next,_dis;
}e[N];
ll tot,head[N],dis[N];
struct Node{
  ll u,dis;
  bool operator <(const Node &a) const {
    return a.dis<dis;
  }
}s[N];
bool vis[N];
void add_edge(ll u,ll v,ll w){
  tot++;
  e[tot]._to=v;
  e[tot]._next=head[u];
  e[tot]._dis=w;
  head[u]=tot;
}
inline void in(ll &x){
  ll f=1;
  x=0;
  char c=getchar();
  while(c>'9'||c<'0'){
    if(c=='-')f=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=f;
}
priority_queue<Node>q;
void dij(ll s){
  q.push(Node{s,0});
  dis[s]=0;
  while(q.size()){
    Node tmp=q.top();
    q.pop();
    if(vis[tmp.u])continue;
    vis[tmp.u]=1;
    for(ll i=head[tmp.u];i;i=e[i]._next){
      ll v=e[i]._to;
      if(dis[tmp.u]+e[i]._dis<dis[v]){
        dis[v]=e[i]._dis+dis[tmp.u];
        if(vis[v])continue;
        q.push(Node{v,dis[v]});
      }
    } 
  }
}
ll main(){
  freopen("4779.in","r",stdin);
  freopen("4779.out","w",stdout);
  ll n,m,s;
  in(n);in(m);in(s);
  memset(dis,0x3f,sizeof(dis));
  for(ll i=1;i<=m;i++){
    ll u,v,w;
    in(u);in(v);in(w);
    add_edge(u,v,w);
  }
  dij(s);
  for(ll i=1;i<=n;i++)cout<<((dis[i]==0x3f3f3f3f)?(2147483647):dis[i])<<' ';
  return 0;
}
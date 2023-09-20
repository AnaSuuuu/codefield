#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
ll tot,c[N],n;
struct Node{
  ll id,p;
}s[N];
ll head[N],ans[N];
struct Edge{
  ll _to,_next;
}e[N];
void add_edge(ll u,ll v){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  head[u]=tot;
}
ll lowbit(ll x){
  return x&(-x);
}
bool cmp1(Node x,Node y){
  return x.p<y.p;
}
bool cmp2(Node x,Node y){
  return x.id<y.id;
}
void add(ll x){
  for(ll i=x;i<=n;i+=lowbit(i))c[i]++;
}
ll query(ll x){
  ll ans=0;
  for(ll i=x;i;i-=lowbit(i))ans+=c[i];
  return ans;
}
void dfs(ll u,ll fa){
  ll tmp=query(n)-query(s[u].p);
  for(ll i=head[u];i;i=e[i]._next){
    ll v=e[i]._to;
    if(v==fa)continue;
    add(s[v].p);
    dfs(v,u);
  }
  ans[u]=query(n)-query(s[u].p)-tmp;
}
ll main(){
  freopen("3605.in","r",stdin);
  freopen("3605.out","w",stdout);
  scanf("%d",&n);
  for(ll i=1;i<=n;i++)scanf("%d",&s[i].p),s[i].id=i;
  sort(s+1,s+1+n,cmp1);
  for(ll i=1;i<=n;i++)s[i].p=i;
  sort(s+1,s+1+n,cmp2);
  for(ll i=2;i<=n;i++){
    ll fa;
    scanf("%d",&fa);
    add_edge(fa,i);
  }
  dfs(1,0);
  for(ll i=1;i<=n;i++)prllf("%d\n",ans[i]);
  return 0;
}
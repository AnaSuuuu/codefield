#include<bits/stdc++.h>
using namespace std;
const ll N=2e5+5;
struct Edge{
  ll _next,_to;
}e[N*2];
struct Node{
  ll x,y;
}s[2*N];
ll fa[2*N],vis[N*2],A[N*2];
ll head[N*2],tot,kk[N*2];
ll get_fa(ll x){
  return (fa[x]==x)?x:(fa[x]=get_fa(fa[x]));
}
void add_edge(ll u,ll v){
  e[++tot]._next=head[u];
  e[tot]._to=v;
  head[u]=tot;
}
ll main(){
  freopen("1197.in","r",stdin);
  freopen("1197.out","w",stdout);
  ll n,m,k,ans;
  cin>>n>>m;
  for(ll i=0;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++){
  	ll x,y;
  	cin>>x>>y;
  	add_edge(x,y);
  	add_edge(y,x);
    s[i].x=x;s[i].y=y;
  }
  cin>>k;
  for(ll i=1;i<=k;i++){
    ll x;
    cin>>x;
    kk[i]=x;
    vis[x]=1;
  }
  ll kdl=k+1;
  ans=n-k;
  for(ll i=1;i<=m*2;i++){
    if(vis[s[i].x]==0&&vis[s[i].y]==0){
      ll fx=get_fa(s[i].x),fy=get_fa(s[i].y);
      if(fx==fy)continue;
      fa[fx]=fy;
      ans--;
    }
  }
  A[kdl--]=ans;
  for(ll i=k;i>=1;i--){
    ans++;
    vis[kk[i]]=0;
    for(ll j=head[kk[i]];j;j=e[j]._next){
      ll v=e[j]._to;
      if(vis[kk[i]]==0&&vis[v]==0){
        ll fx=get_fa(kk[i]),fy=get_fa(v);
        if(fx==fy)continue;
        fa[fx]=fy;ans--;
      }
    }
    A[kdl--]=ans;
  }
  for(ll i=1;i<=k+1;i++)cout<<A[i]<<endl;
  return 0;
}

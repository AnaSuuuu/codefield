#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
struct Node{
  ll x,y,t;
}s[N];
ll fa[N];
bool cmp(Node x,Node y){
  return x.t<y.t;
}
ll find_fa(ll x){
  if(fa[x]==x)return x;
  return fa[x]=find_fa(fa[x]);
}
ll main(){
  freopen("1111.in","r",stdin);
  freopen("1111.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++)
    cin>>s[i].x>>s[i].y>>s[i].t;
  sort(s+1,s+1+m,cmp);
  ll las_upd=0;
  for(ll i=1;i<=m;i++){
    if(find_fa(s[i].x)==find_fa(s[i].y))continue;
    else {
      fa[find_fa(s[i].x)]=find_fa(s[i].y);
      las_upd=s[i].t;
    }
  }
  for(ll i=1;i<n;i++){
    if(find_fa(i)!=find_fa(i+1)){
      puts("-1");
      return 0;
    }
  }
  cout<<las_upd<<endl;
  return 0;
}
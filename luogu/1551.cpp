#include<bits/stdc++.h>
using namespace std;
const ll N=5005;
ll fa[N];
inline ll get_fa(ll x){
  return (x==fa[x]?x:get_fa(fa[x]));
}
ll main(){
  freopen("1551.in","r",stdin);
  freopen("1551.out","w",stdout);
  ll n,m,p;
  cin>>n>>m>>p;
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++){
    ll x,y;
    cin>>x>>y;
    ll fx=get_fa(x),fy=get_fa(y);
    fa[fx]=fy;
  }
  for(ll i=1;i<=p;i++){
    ll x,y;
    cin>>x>>y;
    ll fx=get_fa(x),fy=get_fa(y);
    if(fx==fy)puts("Yes");
    else puts("No");
  }
  return 0;
}
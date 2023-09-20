#include<bits/stdc++.h>
using namespace std;
const ll N=2e4+5;
ll fa[N],_fa[N];
inline ll get_fa(ll x){
  return (x==fa[x]?x:get_fa(fa[x]));
}
inline ll _get_fa(ll x){
  return (x==_fa[x]?x:_get_fa(_fa[x]));
}
ll main(){
  freopen("2078.in","r",stdin);
  freopen("2078.out","w",stdout);
  ll n,m,p,q;
  ll ans1=1,ans2=1;
  scanf("%d%d%d%d",&n,&m,&p,&q);
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++)_fa[i]=i;
  for(ll i=1;i<=p;i++){
    ll x,y;
    scanf("%d%d",&x,&y);
    ll fx=get_fa(x),fy=get_fa(y);
    fa[fx]=fy;
  }
  for(ll i=1;i<=q;i++){
    ll x,y;
    scanf("%d%d",&x,&y);
    x=-x,y=-y;
    ll fx=_get_fa(x),fy=_get_fa(y);
    _fa[fx]=fy;
  }
  ll ff=get_fa(1);
  for(ll i=2;i<=n;i++){
    if(get_fa(i)==ff)ans1++;
  }
  ff=_get_fa(1);
  for(ll i=2;i<=m;i++)
    if(_get_fa(i)==ff)ans2++;
  //cout<<ans1<<' '<<ans2<<endl;
  prllf("%d\n",min(ans1,ans2));
  return 0;
}
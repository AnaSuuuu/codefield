#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
ll fa[N];
inline ll get_fa(ll x){
  return (x==fa[x]?x:get_fa(fa[x]));
}
ll main(){
  freopen("1536.in","r",stdin);
  freopen("1536.out","w",stdout);
  ll n,m,ans;
  scanf("%d",&n);
  while(n!=0){
    scanf("%d",&m);
    for(ll i=1;i<=n;i++)fa[i]=i;
    ans=n-1;
    for(ll i=1;i<=m;i++){
      ll a,b;
      cin>>a>>b;
      ll fc=get_fa(a),fb=get_fa(b);
      if(fc!=fb)ans--;
      fa[fc]=fb;
    }
    cout<<max(ans,0)<<endl;
    scanf("%d",&n);
  }
  return 0;
}
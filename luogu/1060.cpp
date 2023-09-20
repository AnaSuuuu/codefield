#include<bits/stdc++.h>
using namespace std;
const ll N=3e4+5;
ll v[N],p[N],f[N];
ll main(){
  freopen("1060.in","r",stdin);
  freopen("1060.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=m;i++)
    cin>>v[i]>>p[i];
  for(ll i=1;i<=m;i++){
    for(ll j=n;j>=v[i];j--)
      f[j]=max(f[j],f[j-v[i]]+v[i]*p[i]);
  }
  ll ans=0;
  for(ll i=1;i<=n;i++)ans=max(ans,f[i]);
  cout<<ans<<endl;
  return 0;
}
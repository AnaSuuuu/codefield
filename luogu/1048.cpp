#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
ll f[N];
ll v[N],w[N];
ll main(){
  freopen("1048.in","r",stdin);
  freopen("1048.out","w",stdout);
  ll t,m;
  cin>>t>>m;
  for(ll i=1;i<=m;i++)cin>>w[i]>>v[i];
  for(ll i=1;i<=m;i++)
    for(ll j=t;j>=w[i];j--)
      f[j]=max(f[j],f[j-w[i]]+v[i]);
  ll ans=0;
  for(ll i=1;i<=t;i++)ans=max(ans,f[i]);
  cout<<ans<<endl;
  return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
const ll M=1e7+5;
ll a[N],b[N];
ll f[M];
ll main(){
  freopen("1616.in","r",stdin);
  freopen("1616.out","w",stdout);
  ll t,m;
  cin>>t>>m;
  for(ll i=1;i<=m;i++)
    cin>>a[i]>>b[i];
  ll ans=0;
  memset(f,0,sizeof(f));
  for(ll i=1;i<=m;i++)
    for(ll j=a[i];j<=t;j++)
      f[j]=max(f[j],f[j-a[i]]+b[i]),ans=max(ans,f[j]);
  cout<<ans<<endl;
  return 0;
}
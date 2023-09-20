#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+5;
ll a[N],b[N],c[N];
ll f[N];
ll main(){
  freopen("1802.in","r",stdin);
  freopen("1802.out","w",stdout);
  ll n,x;
  cin>>n>>x;
  for(ll i=1;i<=n;i++){
    cin>>a[i]>>b[i]>>c[i];
    f[0]+=a[i];
    b[i]-=a[i];
  }
  for(ll i=1;i<=n;i++){
    for(ll j=x;j>=c[i];j--){
      f[j]=max(f[j],f[j-c[i]]+b[i]);
    }
  }
  ll ans=0;
  for(ll i=0;i<=x;i++)ans=max(ans,f[i]);
  cout<<ans*5<<endl;
  return 0;
}
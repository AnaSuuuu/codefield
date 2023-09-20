#include<bits/stdc++.h>
using namespace std;
const ll N=105;
ll a[N<<1];
ll f[N<<1][N<<1];
inline ll sum(ll l,ll r){
  ll tot=0;
  for(ll i=l;i<=r;i++)tot+=a[i];
  return tot;
}
ll main(){
  freopen("1880.in","r",stdin);
  freopen("1880.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
  memset(f,0x3f,sizeof(f));
  for(ll i=1;i<=(n<<1);i++)f[i][i]=0;
  for(ll len=1;len<=n;len++){
    for(ll i=1;i+len-1<=(n<<1);i++){
      ll j=i+len-1;
      for(ll k=i;k<j;k++)
        f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum(i,j));
    }
  }
  ll ans=0x3f3f3f3f;
  for(ll i=1;i<=n;i++)ans=min(ans,f[i][i+n-1]);
  cout<<ans<<endl;
  memset(f,0,sizeof(f));
  for(ll len=1;len<=n;len++){
    for(ll i=1;i+len-1<=(n<<1);i++){
      ll j=i+len-1;
      for(ll k=i;k<j;k++)
        f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+sum(i,j));
    }
  }
  ans=0;
  for(ll i=1;i<=n;i++)ans=max(ans,f[i][i+n-1]);
  cout<<ans<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
ll s[N][N],f[N][N];
ll main(){
  freopen("1216.in","r",stdin);
  freopen("1216.out","w",stdout);
  ll r;
  cin>>r;
  for(ll i=1;i<=r;i++)
    for(ll j=1;j<=i;j++)
      cin>>s[i][j];
  f[1][1]=s[1][1];
  for(ll i=2;i<=r;i++){
    for(ll j=1;j<=i;j++){
      f[i][j]=max(f[i-1][j],f[i-1][max(1,j-1)])+s[i][j];
    }
  }
  ll ans=0;
  for(ll i=1;i<=r;i++)ans=max(ans,f[r][i]);
  cout<<ans<<endl;
  return 0;
}
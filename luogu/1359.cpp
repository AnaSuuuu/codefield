#include<bits/stdc++.h>
using namespace std;
const ll N=205;
ll a[N][N];
ll dp[N];
ll main(){
  freopen("1359.in","r",stdin);
  freopen("1359.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<n;i++)
    for(ll j=i+1;j<=n;j++)
      cin>>a[i][j];
  memset(dp,0x3f,sizeof(dp));
  dp[1]=0;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<i;j++)
      dp[i]=min(dp[i],dp[j]+a[j][i]);
  }
  cout<<dp[n]<<endl;
  return 0;
}
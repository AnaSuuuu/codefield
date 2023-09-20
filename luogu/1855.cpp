#include<bits/stdc++.h>
using namespace std;
const ll N=105;
const ll M=405;
struct Node{
  ll h,t,k;
}s[N];
ll dp[M][M],ans;
ll main(){
  freopen("1855.in","r",stdin);
  freopen("1855.out","w",stdout);
  ll h,t,n;
  cin>>n>>h>>t;
  for(ll i=1;i<=n;i++)cin>>s[i].h>>s[i].t;
  for(ll i=1;i<=n;i++){
    for(ll j=h;j>=s[i].h;j--){
      for(ll k=t;k>=s[i].t;k--){
        dp[j][k]=max(dp[j][k],dp[j-s[i].h][k-s[i].t]+1);
        ans=max(ans,dp[j][k]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
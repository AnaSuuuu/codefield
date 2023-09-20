#include<bits/stdc++.h>
using namespace std;
const ll N=55;
const ll M=405;
struct Node{
  ll h,t,k;
}s[N];
ll dp[M][M],ans;
ll main(){
  freopen("1507.in","r",stdin);
  freopen("1507.out","w",stdout);
  ll h,t,n;
  cin>>h>>t;
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>s[i].h>>s[i].t>>s[i].k;
  for(ll i=1;i<=n;i++){
    for(ll j=h;j>=s[i].h;j--){
      for(ll k=t;k>=s[i].t;k--){
        dp[j][k]=max(dp[j][k],dp[j-s[i].h][k-s[i].t]+s[i].k);
        ans=max(ans,dp[j][k]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
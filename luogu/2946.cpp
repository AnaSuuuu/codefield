/*#include<bits/stdc++.h>
using namespace std;
const ll mod=1e8;
const ll N=2005;
ll a[N],n,f,ans;
ll dp[N][N];
ll main(){
  freopen("2946.in","r",stdin);
  freopen("2946.out","w",stdout);
  cin>>n>>f;
  for(ll i=1;i<=n;i++)cin>>a[i],a[i]%=f;
  //dp[0][0]=1;
  for(ll i=1;i<=n;i++){
    dp[i][a[i]]=1;
    for(ll j=f-1;j>=0;j--){
      dp[i][j]=(dp[i][j]+(dp[i-1][j]+dp[i-1][(j-a[i]+f)%f])%mod)%mod;
    }
  }
  cout<<dp[n][0]<<endl;
  return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const ll mod=1e8;
const ll N=2005;
ll a[N],n,f,ans;
ll dp[N][N];
ll dfs(ll kdl,ll cnt){
  if(dp[kdl][cnt]!=-1)return dp[kdl][cnt];
  ll AAA=0;
  if(kdl==n+1)return dp[kdl][cnt]=0;
  AAA=AAA+dfs(kdl+1,(cnt+a[kdl])%f)+((cnt+a[kdl])%f==0);
  AAA=AAA+dfs(kdl+1,cnt);
  return dp[kdl][cnt]=AAA;
}
ll main(){
  freopen("2946.in","r",stdin);
  freopen("2946.out","w",stdout);
  memset(dp,-1,sizeof(dp));
  cin>>n>>f;
  for(ll i=1;i<=n;i++)cin>>a[i],a[i]%=f;
  cout<<dfs(1,0)<<endl;
  return 0;
}
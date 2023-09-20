#include<bits/stdc++.h>
using namespace std;
const ll N=105;
const ll zh[][2]={{1,0},{-1,0},{0,1},{0,-1}};
ll dp[N][N],ans,s[N][N];
ll n,m;
void dfs(ll x,ll y,ll step){
  if(dp[x][y]){
    ans=max(ans,step-1+dp[x][y]);
    return ;
  }
  ans=max(ans,step);
  for(ll i=0;i<4;i++){
    ll dx=x+zh[i][0],dy=y+zh[i][1];
    if(dx>n||dx<1||dy>m||dy<1)continue;
    if(s[dx][dy]<s[x][y])dfs(dx,dy,step+1);
  }
}
ll main(){
  freopen("1434.in","r",stdin);
  freopen("1434.out","w",stdout);
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++)cin>>s[i][j];
  }
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      ans=1;
      dfs(i,j,1);
      dp[i][j]=ans;
    }
  }
  ans=0;
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++)
      ans=max(ans,dp[i][j]);
  cout<<ans<<endl;
  return 0;
}
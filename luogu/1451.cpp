#include<bits/stdc++.h>
using namespace std;
const ll N=105;
ll s[N][N],zh[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
ll n,m,ans;
bool vis[N][N];
void dfs(ll x,ll y){
  vis[x][y]=1;
  for(ll i=0;i<4;i++){
    ll dx=x+zh[i][0],dy=y+zh[i][1];
    if(dx<=0||dx>n||dy<=0||dy>m)continue;
    if(vis[dx][dy]||s[dx][dy]==0)continue;
    dfs(dx,dy);
  }
}
ll main(){
  freopen("1451.in","r",stdin);
  freopen("1451.out","w",stdout);
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++)
      scanf("%1d",&s[i][j]);
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
      if(vis[i][j]||s[i][j]==0)continue;
      dfs(i,j);
      ans++;//cout<<i<<' '<<j<<endl;;
    }
  }
  cout<<ans<<endl;
  return 0;
}
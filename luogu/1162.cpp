#include<bits/stdc++.h>
using namespace std;
const ll N=35;
const ll zh[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
ll a[N][N],n;
bool vis[N][N];
void dfs(ll x,ll y){
  vis[x][y]=1;
  for(ll i=0;i<4;i++){
    ll dx=x+zh[i][0],dy=y+zh[i][1];
    if(x>n||x<1||y>n||y<1)continue;
    if(vis[dx][dy])continue;
    if(a[dx][dy])continue;
    vis[dx][dy]=1;
    dfs(dx,dy);
  }
}
ll main(){
  freopen("1162.in","r",stdin);
  freopen("1162.out","w",stdout);
  cin>>n;
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++)
      cin>>a[i][j];
  for(ll i=1;i<=n;i++){
    if(vis[1][i]==0&&a[1][i]==0)dfs(1,i);
    if(vis[n][i]==0&&a[n][i]==0)dfs(n,i);
    if(vis[i][1]==0&&a[i][1]==0)dfs(i,1);
    if(vis[i][n]==0&&a[i][n]==0)dfs(i,n);
  } 
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      if(vis[i][j]==0&&a[i][j]==0)cout<<2<<' ';
      else cout<<a[i][j]<<' ';
    }
    cout<<endl;
  }
  return 0;
}
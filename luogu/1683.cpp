#include<bits/stdc++.h>
using namespace std;
const ll N=25;
char s[N][N];
const ll zh[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
ll n,m,ans;
bool vis[N][N];
void dfs(ll x,ll y){
  ans++;
  //cout<<x<<' '<<y<<endl;
  vis[x][y]=1;
  for(ll i=0;i<4;i++){
    ll dx=x+zh[i][0],dy=y+zh[i][1];
    if(dx>n||dx<1||dy>m||dy<1)continue;
    if(s[dx][dy]=='#')continue;
    if(vis[dx][dy])continue;
    dfs(dx,dy);
  }
  return ;
}
ll main(){
  freopen("1683.in","r",stdin);
  freopen("1683.out","w",stdout);
  scanf("%d %d\n",&m,&n);
  for(ll i=1;i<=n;i++)
    scanf("%s\n",s[i]+1);
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
      if(s[i][j]=='@')dfs(i,j);
    }
  }
  /*for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++)cout<<s[i][j];
    cout<<endl;
  }*/
  cout<<ans<<endl;
  return 0;
}
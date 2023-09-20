#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
const ll zh[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
ll s[N][N],ans,n,m;
ll Ans[N][N];
bool vis[N][N];
struct Node {
  ll x,y;
};
queue<Node> q;
void dfs(ll x,ll y){
  ans++;
  q.push((Node){x,y});
  //cout<<x<<' '<<y<<endl;
  vis[x][y]=1;
  for(ll i=0;i<4;i++){
    ll dx=x+zh[i][0],dy=zh[i][1]+y;
    if(dx>n||dx<1||dy>n||dy<1)continue;
    if(vis[dx][dy])continue;
    if(s[x][y]^s[dx][dy]){
      vis[dx][dy]=1;
      dfs(dx,dy);
    }
  }
}
ll main(){
  freopen("1141.in","r",stdin);
  freopen("1141.out","w",stdout);
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++)
      scanf("%1d",&s[i][j]);
  while(m--){
    ll x,y;
    ans=0;
    //memset(vis,0,sizeof(vis));
    cin>>x>>y;
    if(Ans[x][y]){
      cout<<Ans[x][y]<<endl;
      continue;
    }
    dfs(x,y);
    cout<<ans<<endl;
    while(q.size()){
      Ans[q.front().x][q.front().y]=ans;
      q.pop();
    }
  }
  return 0;
}
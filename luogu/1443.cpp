#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
struct Node{
  ll x,y,step;
};
ll ans[405][405];
const ll zh[8][2]={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
queue<Node> q;
bool vis[405][405];
ll main(){
  freopen("1443.in","r",stdin);
  freopen("1443.out","w",stdout);
  ll n,m,x,y;
  cin>>n>>m>>x>>y;
  q.push(Node{x,y,0});
  ll kdl=n*m-1;
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++)
      ans[i][j]=-1;
  while(q.size()){
    Node tmp=q.front();
    q.pop();
    ll dx=tmp.x,dy=tmp.y;
    vis[dx][dy]=1;
    ans[dx][dy]=tmp.step;
    for(ll i=0;i<8;i++){
      ll ddx=dx+zh[i][0],ddy=dy+zh[i][1];
      if(ddx<=0||ddx>n||ddy<=0||ddy>m)continue;
      if(vis[ddx][ddy])continue;
      q.push(Node{ddx,ddy,tmp.step+1});vis[ddx][ddy]=1;
    }
  }
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++)cout<<ans[i][j]<<' ';
    cout<<endl;
  }
  return 0;
}
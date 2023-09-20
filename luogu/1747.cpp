#include<bits/stdc++.h>
using namespace std;
const ll zh[][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1},{2,2},{2,-2},{-2,2},{-2,-2}};
bool vis[35][35];
struct Node{
  ll x,y,step;
};
void bfs(ll x,ll y){
  queue<Node> q;
  q.push(Node{x,y,0});
  memset(vis,0,sizeof(vis));
  vis[x][y]=1;
  while(!q.empty()){
    Node tmp=q.front();
    q.pop();
    //vis[tmp.x][tmp.y]=0;
    if(tmp.x==1&&tmp.y==1){
      prllf("%d\n",tmp.step);
      return ;
    }
    for(ll i=0;i<12;i++){
      ll dx=tmp.x+zh[i][0],dy=tmp.y+zh[i][1];
      if(dx<1||dy<1)continue;
      if(vis[dx][dy])continue;
      q.push(Node{dx,dy,tmp.step+1});
      vis[dx][dy]=1;
    }
  }
}
ll main(){
  freopen("1747.in","r",stdin);
  freopen("1747.out","w",stdout);
  ll x0,y0,x1,y1;
  cin>>x0>>y0>>x1>>y1;
  bfs(x0,y0);
  bfs(x1,y1);
  return 0;
}
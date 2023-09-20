#include<bits/stdc++.h>
using namespace std;
int h,w,ans;
int s[15][15];
map<int,int>vis;
const int zh[][2]={{1,0},{0,1}};
void dfs(int x,int y){
  if(x==h&&y==w){
    ans++;
    return ;
  }
  for(int i=0;i<2;i++){
    int dx=x+zh[i][0],dy=y+zh[i][1];
    if(dx>h||dy>w)continue;
    if(vis[s[dx][dy]])continue;
    vis[s[dx][dy]]=1;
    dfs(dx,dy);
    vis[s[dx][dy]]=0;
  }
}
int main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  scanf("%d%d",&h,&w);
  for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)
      scanf("%d",&s[i][j]);
  vis[s[1][1]]=1;
  dfs(1,1);
  cout<<ans<<endl;
  return 0;
}
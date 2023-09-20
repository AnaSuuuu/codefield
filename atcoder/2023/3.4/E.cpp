#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int tot,head[N];
struct Edge{
  int _to,_next;
}e[N];
int ans,dis[N],vis[N],vv[N];
void add_edge(int u,int v){
  tot++;
  e[tot]._next=head[u];
  e[tot]._to=v;
  head[u]=tot;
}
void spfa(int s){
  queue<int>q;
  q.push(s);
  dis[s]=0;
  while(q.size()){
    int u=q.front();
    q.pop();
    if(u!=s&&vv[u]==0)ans++,vv[u]=1;
    if(dis[u]==1)ans--;
    vis[u]=0;
    for(int i=head[u];i;i=e[i]._next){
      int v=e[i]._to;
      if(dis[v]>dis[u]+1){
        dis[v]=dis[u]+1;
        if(!vis[v])q.push(v);
        vis[v]=1;
      }
    }
  }
}
int main(){
  freopen("E.in","r",stdin);
  freopen("E.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    add_edge(u,v);
  }  
  for(int i=1;i<=n;i++){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(vv,0,sizeof(vv));
    spfa(i);
  }
  printf("%d\n",ans);
  return 0;
}

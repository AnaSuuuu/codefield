#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int a[N];
struct Edge{
  int _to,_next;
}e[N<<1];
int head[N],tot,f[N];
int dis[N],vis[N];
void add_edge(int u,int v){
  e[++tot]._next=head[u];
  e[tot]._to=v;
  head[u]=tot;
}
void spfa(){
  queue<int> q;
  q.push(1);
  memset(dis,0x3f,sizeof(dis));
  dis[1]=0;
  vis[1]=1;
  while(q.size()){
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(int i=head[u];i;i=e[i]._next){
      int v=e[i]._to;
      if(dis[v]>dis[u]+1){
        dis[v]=dis[u]+1;
        if(!vis[v]){
          q.push(v);
          vis[v]=1;
        }
      }
    }
  }
}
int main(){
  int n,m,t;
  scanf("%d%d%d",&n,&m,&t);
  for(int i=2;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }
  spfa();
  for(int i=1;i<=t;i++){
    for(int j=1;j<=n;j++){
      if(i>=dis[j]*2)f[i]=max(f[i],f[i-dis[j]*2]+a[j]);
    }
  }
  for(int i=1;i<=t;i++)printf("%d ",f[i]);
  return 0;
}
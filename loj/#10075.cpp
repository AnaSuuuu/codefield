#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
  int a,b,t;
}s[N];
struct Edge{
  int _to,_next,_dis;
}e[N];
bool cmp(Node x,Node y){
  return x.a==y.a?(x.b==y.b?x.t<y.t:x.b<y.b):x.a<y.a;
}
int dis[1005],vis[1005];
int dis0[1005];
int tot,head[1005];
void add_edge(int u,int v,int w){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  e[tot]._dis=w;
  head[u]=tot;
}
void spfa(int s){
  queue<int> q;
  q.push(s);
  memset(dis,0x3f,sizeof(dis));
  memset(vis,0,sizeof(vis));
  dis[s]=0;
  vis[s]=1;
  while(q.size()){
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(int i=head[u];i;i=e[i]._next){
      int v=e[i]._to;
      if(dis[v]>dis[u]+e[i]._dis){
        dis[v]=dis[u]+e[i]._dis;
        if(!vis[v])q.push(v);
        vis[v]=1;
      }
    }
  }
}
int main(){
  freopen("#10075.in","r",stdin);
  freopen("#10075.out","w",stdout);
  int n,m,x;
  scanf("%d%d%d",&n,&m,&x);
  for(int i=1;i<=m;i++)scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].t);
  sort(s+1,s+1+m,cmp);
  for(int i=1;i<=m;i++){
    if(s[i].a==s[i-1].a&&s[i].b==s[i-1].b)continue;
    add_edge(s[i].b,s[i].a,s[i].t);
  }
  spfa(x);
  int ans=0;
  for(int i=1;i<=n;i++)dis0[i]+=dis[i];
  memset(head,0,sizeof(head));
  tot=0;
  for(int i=1;i<=m;i++){
    if(s[i].a==s[i-1].a&&s[i].b==s[i-1].b)continue;
    add_edge(s[i].a,s[i].b,s[i].t);
  }
  spfa(x);
  for(int i=1;i<=n;i++)dis0[i]+=dis[i];
  for(int i=1;i<=n;i++)ans=max(ans,dis0[i]);
  printf("%d\n",ans);
  return 0;
}
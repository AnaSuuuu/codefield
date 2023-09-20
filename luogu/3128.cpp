#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int tot,head[N],rt[N];
int son[N],dep[N],fa[N];
int sum[N],top[N],ans[N];
struct Edge{
  int _to,_next;
}e[N<<1];
void add_edge(int u,int v){
  e[++tot]._next=head[u];
  e[tot]._to=v;
  head[u]=tot;
}
void dfs0(int u){
  sum[u]=1;
  int Max=-1;
  for(int i=head[u];i;i=e[i]._next){
    int v=e[i]._to;
    if(!dep[v]){
      dep[v]=dep[u]+1;
      fa[v]=u;
      dfs0(v);
      sum[u]+=sum[v];
      if(sum[v]>Max)Max=sum[v],son[u]=v;
    }
  }
}
void dfs1(int u,int topf){
  top[u]=topf;
  if(!son[u])return ;
  dfs1(son[u],topf);
  for(int i=head[u];i;i=e[i]._next)
    if(!top[e[i]._to])dfs1(e[i]._to,e[i]._to);
}
int lca(int x,int y){
  while(top[x]!=top[y]){
    if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
    x=fa[top[x]];
  }
  return dep[x]<dep[y]?x:y;
}
void dfs2(int u){
  ans[u]=rt[u];
  for(int i=head[u];i;i=e[i]._next){
    int v=e[i]._to;
    if(v==fa[u])continue;
    //cout<<v<<endl;
    dfs2(v);
    ans[u]+=ans[v];
  }
}
int main(){
  freopen("3128.in","r",stdin);
  freopen("3128.out","w",stdout);
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=1;i<n;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }
  dep[1]=1;
  dfs0(1);
  //for(int i=1;i<=n;i++)cout<<fa[i]<<' ';
  //cout<<endl;
  dfs1(1,1);
  //for(int i=1;i<=n;i++)cout<<fa[i]<<' ';
  //cout<<endl;
  for(int i=1;i<=k;i++){
    int s,t;
    scanf("%d%d",&s,&t);
    rt[s]++,rt[t]++;
    rt[lca(s,t)]--;
    if(fa[lca(s,t)])rt[fa[lca(s,t)]]--;
  }
  /*for(int i=1;i<=n;i++)cout<<fa[i]<<' ';
  cout<<endl;*/
  dfs2(1);
  int Ans=0;
  for(int i=1;i<=n;i++)Ans=max(Ans,ans[i]);
  cout<<Ans<<endl;
  return 0;
}
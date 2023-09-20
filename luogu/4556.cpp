#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=6e6+6;
int n,m,tot,maxn;
int x[N],y[N],z[N];
int sum[N],cnt,fa[N];
int head[N],dep[N];
int L[M],R[M],rt[N];
int ans[N],son[N],top[N];
struct T{
  int val,maxx;
}tr[M];
struct Edge{
  int _next,_to;
}e[N<<1];
void add_edge(int u,int v){
  e[++tot]._to=v;
  e[tot]._next=head[u];
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
void pushup(int root){
  if(tr[L[root]].val>=tr[R[root]].val){
    tr[root].maxx=tr[L[root]].maxx;
    tr[root].val=tr[L[root]].val;
  }
  else {
    tr[root].maxx=tr[R[root]].maxx;
    tr[root].val=tr[R[root]].val;
  }
}
int lca(int x,int y){
  while(top[x]!=top[y]){
    if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
    x=fa[top[x]];
  }
  if(dep[x]<dep[y])return x;
  return y;
}
int change(int root,int l,int r,int pos,int val){
  if(!root)root=++cnt;
  int mid=l+r>>1;
  if(l==r){
    tr[root].maxx=pos;
    tr[root].val+=val;
    return root;
  }
  if(mid>=pos)L[root]=change(L[root],l,mid,pos,val);
  else R[root]=change(R[root],mid+1,r,pos,val);
  pushup(root);
  return root;
}
int merge(int x,int y,int l,int r){
  if(!x)return y;
  if(!y)return x;
  if(l==r){
    tr[x].val+=tr[y].val;
    tr[x].maxx=l;
    return x;
  }
  int mid=l+r>>1;
  L[x]=merge(L[x],L[y],l,mid);
  R[x]=merge(R[x],R[y],mid+1,r);
  pushup(x);
  return x;
}
void dfs2(int u,int f){
  for(int i=head[u];i;i=e[i]._next){
    int v=e[i]._to;
    if(v==fa[u])continue;
    dfs2(v,u);
    rt[u]=merge(rt[u],rt[v],1,maxn);
  }
  if(tr[rt[u]].val)ans[u]=tr[rt[u]].maxx;
}
int main(){
  freopen("4556.in","r",stdin);
  freopen("4556.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<n;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }
  dep[1]=1;
  dfs0(1);
  dfs1(1,1);
  for(int i=1;i<=m;i++){
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
    maxn=max(maxn,z[i]);
  }
  for(int i=1;i<=m;i++){
    int LCA=lca(x[i],y[i]);
    //cout<<LCA<<endl;
    rt[x[i]]=change(rt[x[i]],1,maxn,z[i],1);
    rt[y[i]]=change(rt[y[i]],1,maxn,z[i],1);
    rt[LCA]=change(rt[LCA],1,maxn,z[i],-1);
    if(fa[LCA])rt[fa[LCA]]=change(rt[fa[LCA]],1,maxn,z[i],-1);/**/
  }
  dfs2(1,0);
  for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
  return 0;
}
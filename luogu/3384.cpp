#include<bits/stdc++.h>
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int N=1e5+5;
int n,m,r,p;
int s[N],head[N],tot;
int sum[N],son[N],dep[N],top[N];
int id[N],cnt,fa[N],neew[N];
struct Edge{
  int _to,_next;
}e[N<<1];
struct T{
  int sum,tag;
}tr[N<<2];
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
  id[u]=++cnt;
  neew[cnt]=s[u];
  if(!son[u])return ;
  dfs1(son[u],topf);
  for(int i=head[u];i;i=e[i]._next){
    int v=e[i]._to;
    if(!top[v])dfs1(v,v);
  }
}
void pushup(int root){
  tr[root].sum=(tr[ls].sum+tr[rs].sum)%p;
}
void pushdown(int root,int l,int r){
  int mid=l+r>>1;
  tr[ls].tag=(tr[ls].tag+tr[root].tag)%p;
  tr[ls].sum=(tr[ls].sum+(mid-l+1)*tr[root].tag)%p;
  tr[rs].tag=(tr[rs].tag+tr[root].tag)%p;
  tr[rs].sum=(tr[rs].sum+(r-mid)*tr[root].tag)%p;
  tr[root].tag=0;
}
void build(int root,int l,int r){
  if(l==r){
    tr[root].sum=neew[l]%p;
    return ;
  }
  int mid=l+r>>1;
  build(ls,l,mid);
  build(rs,mid+1,r);
  pushup(root);
}
void update2(int root,int l,int r,int nl,int nr,int val){//(son of x and x) + z
  if(l>=nl&&r<=nr){
    tr[root].sum=(tr[root].sum+val*(r-l+1)%p)%p;
    tr[root].tag=(val+tr[root].tag)%p;
    return ;
  }
  int mid=l+r>>1;
  pushdown(root,l,r);
  if(mid>=nl)update2(ls,l,mid,nl,nr,val);
  if(mid+1<=nr)update2(rs,mid+1,r,nl,nr,val);
  pushup(root);
}
void update1(int root,int l,int r,int x,int y,int val){//x->y +z
  while(top[x]!=top[y]){
    if(dep[top[x]]<=dep[top[y]])x^=y^=x^=y;
    update2(1,1,n,id[top[x]],id[x],val);
    x=fa[top[x]];
  }
  if(dep[x]>dep[y])x^=y^=x^=y;
  update2(1,1,n,id[x],id[y],val);
}
int query2(int root,int l,int r,int nl,int nr){//sum of son of x
  if(l>=nl&&r<=nr){
    tr[root].sum%=p;
    return tr[root].sum;
  }
  pushdown(root,l,r);
  int mid=l+r>>1;
  int ans=0;
  if(mid>=nl)ans=(ans+query2(ls,l,mid,nl,nr))%p;
  if(mid+1<=nr)ans=(ans+query2(rs,mid+1,r,nl,nr))%p;
  pushup(root);
  return ans;
}
int query1(int root,int l,int r,int x,int y){//sum of x->y
  int ans=0;
  //cout<<x<<' '<<y<<endl;
  //cout<<top[x]<<' '<<top[y]<<endl;
  while(top[x]!=top[y]){
    if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
    ans+=query2(1,1,n,id[top[x]],id[x]);
    ans%=p;
    //cout<<x<<endl;
    x=fa[top[x]];
    //cout<<x<<endl;
  }
  if(dep[x]>dep[y])x^=y^=x^=y;
  ans+=query2(1,1,n,id[x],id[y]);
  return ans%p;
}

int main(){
  freopen("3384.in","r",stdin);
  freopen("3384.out","w",stdout);
  scanf("%d%d%d%d",&n,&m,&r,&p);
  for(int i=1;i<=n;i++)scanf("%d",&s[i]);
  for(int i=1;i<n;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }
  dep[r]=1;
  dfs0(r); 
  dfs1(r,r);
  build(1,1,n);
  //for(int i=1;i<=n;i++)cout<<top[i]<<' ';
  //cout<<endl;
  //for(int i=1;i<=n;i++)cout<<fa[i]<<' ';
  //cout<<endl;
  //for(int i=1;i<=n;i++)cout<<id[i]<<' ';
  //cout<<endl;
  for(int i=1;i<=m;i++){
    int op,x,y,z;
    scanf("%d",&op);
    switch(op){
      case 1:{
        scanf("%d%d%d",&x,&y,&z);
        update1(1,1,n,x,y,z);
        break;
      }
      case 2:{
        scanf("%d%d",&x,&y);
        printf("%d\n",query1(1,1,n,x,y));
        break;
      }
      case 3:{
        scanf("%d%d",&x,&z);
        update2(1,1,n,id[x],id[x]+sum[x]-1,z);
        break;
      }
      case 4:{
        scanf("%d",&x);
        printf("%d\n",query2(1,1,n,id[x],id[x]+sum[x]-1));
        break;
      }
    }
    //for(int i=1;i<=(n<<1);i++)cout<<tr[i].sum<<' ';
    //puts("");
  }
  return 0;
}
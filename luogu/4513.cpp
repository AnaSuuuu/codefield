#include<bits/stdc++.h>
#define lson root<<1
#define rson root<<1|1
using namespace std;
const int N=5e5+5;
int a[N];
struct T{
  int max,maxl,maxr,sum;
}tr[N<<2];
void pushup(T &root,const T &Lson,const T &Rson){
  int tmp=-2147483648;
  if(!(Lson.maxr>=0&&Rson.maxl>=0))tmp=max(Lson.maxr,Rson.maxl);
  else tmp=Lson.maxr+Rson.maxl;
  root.max=tmp;
  root.sum=Lson.sum+Rson.sum;
  root.maxl=max(Lson.maxl,Lson.sum+Rson.maxl);
  root.maxr=max(Rson.maxr,Rson.sum+Lson.maxr);
  root.max=max(root.max,max(Lson.max,Rson.max));
}
void build(int root,int l,int r){
  if(l==r){
    tr[root].max=a[l];
    tr[root].maxl=a[l];
    tr[root].maxr=a[l];
    tr[root].sum=a[l];
    return ;
  }
  int mid=(l+r)/2;
  build(lson,l,mid);
  build(rson,mid+1,r);
  pushup(tr[root],tr[lson],tr[rson]);
}
void update(int root,int l,int r,int node,int num){
  if(l==node&&r==node){
    tr[root].max=num;
    tr[root].maxl=num;
    tr[root].maxr=num;
    tr[root].sum=num;
    return ;
  }
  int mid=(l+r)>>1;
  if(mid>=node)update(lson,l,mid,node,num);
  else update(rson,mid+1,r,node,num);
  pushup(tr[root],tr[lson],tr[rson]);
}
T query(int root,int l,int r,int nl,int nr){
  if(l>=nl&&r<=nr){
    return tr[root];
  }
  int mid=(l+r)>>1;
  if(mid>=nl&&mid+1<=nr){
    T kdl;
    pushup(kdl,query(lson,l,mid,nl,nr),query(rson,mid+1,r,nl,nr));
    return kdl;
  }
  else {
    if(mid>=nl)return query(lson,l,mid,nl,nr);
    else return query(rson,mid+1,r,nl,nr);
  }

  pushup(tr[root],tr[lson],tr[rson]);
}
int main(){
  freopen("4513.in","r",stdin);
  freopen("4513.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
  build(1,1,n);
  for(int i=1;i<=m;i++){
    int k;
    scanf("%d",&k);
    switch(k){
      case 1:{
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)a^=b^=a^=b;
        printf("%d\n",query(1,1,n,a,b).max);
        break;
      }
      case 2:{
        int p,s;
        scanf("%d%d",&p,&s);
        update(1,1,n,p,s);
        break;
      }
    }
  }/**/
  //puts("AAA");
  return 0;
}
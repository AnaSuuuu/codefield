#include<bits/stdc++.h>
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int N=1e5+5;
int tr[N<<2],n,m;
double maxn[N<<2];
int query(int root,int l,int r,double val){
  if(maxn[root]<val)return 0;
  if(l==r)return maxn[root]>val;
  int mid=l+r>>1;
  if(maxn[ls]<=val)return query(rs,mid+1,r,val);
  return query(ls,l,mid,val)+tr[root]-tr[ls];
}

void change(int root,int l,int r,int pos,double val){
  if(l==r){
    tr[root]=1;
    maxn[root]=val;
    return ;
  }
  int mid=l+r>>1;
  if(mid>=pos)change(ls,l,mid,pos,val);
  else change(rs,mid+1,r,pos,val);
  maxn[root]=max(maxn[ls],maxn[rs]);
  tr[root]=tr[ls]+query(rs,mid+1,r,maxn[ls]);
  return ;
}
int main(){
  freopen("4198.in","r",stdin);
  freopen("4198.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    change(1,1,n,x,(double)y/x);
    printf("%d\n",tr[1]);
  }
  return 0;
}
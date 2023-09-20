#include<bits/stdc++.h>
#define ll long long
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int N=1e5+5;
ll tr[N<<2],q,m;
void pushup(int root){
  tr[root]=(tr[ls]*tr[rs])%m;
}
void update(int root,int l,int r,int pos,ll val){
  if(l==r){
    tr[root]=val;
    //cout<<l<<' '<<tr[l]<<endl;
    return ;
  }
  int mid=l+r>>1;
  if(mid>=pos)update(ls,l,mid,pos,val);
  if(mid+1<=pos)update(rs,mid+1,r,pos,val);
  pushup(root);
  return ;
}
void build(int root,int l,int r){
  if(l==r){
    tr[root]=1;
    //puts("AAA");
    return ;
  }
  int mid=l+r>>1;
  build(ls,l,mid);
  build(rs,mid+1,r);
  pushup(root);
}
int main(){
  freopen("4588.in","r",stdin);
  freopen("4588.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&q,&m);
    build(1,1,q);
    for(int i=1;i<=q;i++){
      int op;
      scanf("%d",&op);
      switch(op){
        case 1:{
          ll val;
          scanf("%lld",&val);
          update(1,1,q,i,val);
          break;
        }
        case 2:{
          int pos;
          scanf("%d",&pos);
          update(1,1,q,pos,1);
          //cout<<pos<<endl;
        }
      }
      //for(int i=1;i<=2*q;i++)cout<<tr[i]<<' ';
      //cout<<endl;
      printf("%lld\n",tr[1]%m);
    }
  }
  return 0;
}
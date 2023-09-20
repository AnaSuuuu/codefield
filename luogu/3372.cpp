#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll a[N],n,m;
ll tr[N],tag[N];
void in(ll &x){
  x=0;
  ll f=1;
  char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=f;
}
ll ls(ll root){
  return root<<1;
}
ll rs(ll root){
  return root<<1|1;
}
void push_up(ll root){
  tr[root]=tr[ls(root)]+tr[rs(root)];
}
void work(ll l,ll r,ll root,ll k){
  tag[root]+=k;
  tr[root]+=(r-l+1)*k;
}
void push_down(ll l,ll r,ll root){
  ll mid=(l+r)>>1;
  work(l,mid,ls(root),tag[root]);
  work(mid+1,r,rs(root),tag[root]);
  tag[root]=0;
}
void build(ll root,ll l,ll r){
  ll mid=(l+r)>>1;
  if(l==r){
    tr[root]=a[l];
    return ;
  }
  build(ls(root),l,mid);
  build(rs(root),mid+1,r);
  push_up(root);
  return ;
}
void update(ll nl,ll nr,ll l,ll r,ll root,ll num){
  if(l>=nl&&r<=nr){
   tr[root]+=(r-l+1)*num; 
   tag[root]+=num;
   return ; 
  }
  //cout<<l<<' '<<r<<endl;
  push_down(l,r,root);
  ll mid=(l+r)>>1;
  if(mid>=nl)update(nl,nr,l,mid,ls(root),num);
  if(mid<nr)update(nl,nr,mid+1,r,rs(root),num);
  push_up(root);
  return ;
}
ll query(ll nl,ll nr,ll l,ll r,ll root){
  ll ans=0;
  if(l>=nl&&r<=nr)return tr[root];
  ll mid=(l+r)>>1;
  push_down(l,r,root); 
  if(mid>=nl)ans+=query(nl,nr,l,mid,ls(root));
  if(mid<nr)ans+=query(nl,nr,mid+1,r,rs(root));
  return ans;
}
ll main(){
  freopen("3372.in","r",stdin);
  freopen("3372.out","w",stdout);
  in(n);in(m);
  for(ll i=1;i<=n;i++)in(a[i]);
  build (1,1,n);
  for(ll i=1;i<=m;i++){
    ll op;
    in(op);
    switch(op){
      case 1:{
        ll x,y,k;
        in(x);in(y);in(k);
        update(x,y,1,n,1,k);
        break;
      }
      case 2:{
        ll x,y;
        in(x);in(y);
        cout<<query(x,y,1,n,1)<<endl;
        break;
      }
    }
  }
  return 0;
}

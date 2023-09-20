#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5+5;
ll a[N],tag_add[N],tag_mul[N],tr[N];
ll n,m,p;
inline ll ls(ll root){
  return root<<1;
}
inline ll rs(ll root){
  return root<<1|1;
}
void push_up(ll root){
  tr[root]=tr[ls(root)]+tr[rs(root)];
}
void build(ll root,ll l,ll r){
  tag_add[root]=0;
  tag_mul[root]=1;
  ll mid=(l+r)>>1;
  if(l==r){
    tr[root]=a[l];
    tr[root]%=p;
    return ;
  }
  build(ls(root),l,mid);
  build(rs(root),mid+1,r);
  push_up(root);
  return ;
}
void push_down(ll root,ll l,ll r){
  ll mid=(l+r)>>1;
  tr[ls(root)]=(tr[ls(root)]*tag_mul[root]+tag_add[root]*(mid-l+1))%p;
  tr[rs(root)]=(tr[rs(root)]*tag_mul[root]+tag_add[root]*(r-mid))%p;
  tag_mul[ls(root)]*=tag_mul[root];
  tag_mul[ls(root)]%=p;
  tag_mul[rs(root)]*=tag_mul[root];
  tag_mul[rs(root)]%=p;
  tag_add[ls(root)]=tag_add[ls(root)]*tag_mul[root]+tag_add[root];
  tag_add[ls(root)]%=p;
  tag_add[rs(root)]=tag_add[rs(root)]*tag_mul[root]+tag_add[root];
  tag_add[rs(root)]%=p;
  tag_add[root]=0;
  tag_mul[root]=1;
}
void mul(ll nl,ll nr,ll root,ll l,ll r,ll num){
  if(l>=nl&&r<=nr){
    tr[root]=(tr[root]*num)%p;
    tag_add[root]=(tag_add[root]*num)%p;
    tag_mul[root]=(tag_mul[root]*num)%p;
    return ;
  }
  push_down(root,l,r);
  ll mid=(l+r)>>1;
  if(mid>=nl) mul(nl,nr,ls(root),l,mid,num);
  if(mid+1<=nr) mul(nl,nr,rs(root),mid+1,r,num);
  push_up(root); 
  return ;
}
void add(ll nl,ll nr,ll root,ll l,ll r,ll num){
  if(l>=nl&&r<=nr){
    tr[root]=(tr[root]+num*(r-l+1))%p;
    tag_add[root]=(tag_add[root]+num)%p;
    return ;
  }
  push_down(root,l,r);
  ll mid=(l+r)>>1;
  if(mid>=nl) add(nl,nr,ls(root),l,mid,num);
  if(mid+1<=nr) add(nl,nr,rs(root),mid+1,r,num);
  push_up(root); 
  return ;
}
ll query(ll nl,ll nr,ll root,ll l,ll r){
  if(l>=nl&&r<=nr){
    return tr[root];
  }
  ll ans=0;
  push_down(root,l,r);
  ll mid=(l+r)>>1;
  if(mid>=nl) ans=(ans+query(nl,nr,ls(root),l,mid))%p;
  if(mid+1<=nr) ans=(ans+query(nl,nr,rs(root),mid+1,r))%p;
  return ans;
}
ll main(){
  freopen("3373.in","r",stdin);
  freopen("3373.out","w",stdout);
  cin>>n>>m>>p;
  for(ll i=1;i<=n;i++)cin>>a[i];
  build(1,1,n);
  //cout<<tr[1]<<endl;
  for(ll i=1;i<=m;i++){
    ll op;
    cin>>op;
    switch(op){
      case 1:{
        ll x,y,k;
        cin>>x>>y>>k;
        mul(x,y,1,1,n,k);
        break;
      }
      case 2:{
        ll x,y,k;
        cin>>x>>y>>k;
        add(x,y,1,1,n,k); 
        break;
      }
      case 3:{
        ll x,y;
        cin>>x>>y;
        cout<<query(x,y,1,1,n)<<endl;;
        break;
      }/**/
    }
  }
  return 0;
}
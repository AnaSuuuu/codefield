#include<bits/stdc++.h>
using namespace std;
const ll N=2e5+5;
ll a[N],tr[N<<2],tag[N<<2];
inline ll ls(ll root){
  return root<<1;
}
inline ll rs(ll root){
  return root<<1|1;
}
void push_up(ll root){
  tr[root]=tr[ls(root)]+tr[rs(root)];
  return ;
}
void update(ll root,ll l,ll r){
  tag[root]^=1;
  tr[root]=(r-l+1)-tr[root];
  return ;
}
void push_down(ll root,ll l,ll r){
  if(!tag[root])return ;
  ll mid=(l+r)>>1;
  update(ls(root),l,mid);
  update(rs(root),mid+1,r);
  tag[root]=0;
  return ;
}
void build(ll root,ll l,ll r){
  if(l==r){
    tr[root]=a[l];
    return ;
  }
  ll mid=(l+r)>>1;
  build(ls(root),l,mid);
  build(rs(root),mid+1,r);
  push_up(root);
  return ;
}
void Xor(ll nl,ll nr,ll root,ll l,ll r){
  if(l>=nl&&r<=nr){
    tag[root]^=1;
    tr[root]=(r-l+1)-tr[root];
    return ;
  }
  push_down(root,l,r);
  ll mid=(l+r)>>1;
  if(mid>=nl)Xor(nl,nr,ls(root),l,mid);
  if(mid+1<=nr)Xor(nl,nr,rs(root),mid+1,r);
  push_up(root);
} 
inline ll query(ll nl,ll nr,ll root,ll l,ll r){
  if(l>=nl&&r<=nr) return tr[root];
  push_down(root,l,r);
  ll mid=(l+r)>>1,ans=0;
  if(mid>=nl)ans+=query(nl,nr,ls(root),l,mid);
  if(mid+1<=nr)ans+=query(nl,nr,rs(root),mid+1,r);
  return ans;
}
ll main(){
  freopen("2574.in","r",stdin);
  freopen("2574.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)scanf("%1d",&a[i]);
  build(1,1,n);
  while(m--){
    ll op;
    cin>>op;
    switch(op){
      case 0:{
        ll l,r;
        cin>>l>>r;
        Xor(l,r,1,1,n);
        break;
      }
      case 1:{
        ll l,r;
        cin>>l>>r;
        cout<<query(l,r,1,1,n)<<endl;;
        break;
      }
    }
  }
  return 0;
}
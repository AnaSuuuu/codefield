#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a[N],n,p;
struct T{
  ll sum,mul,add;
}tr[N<<2];
ll ls(ll rt){
  return rt<<1;
}
ll rs(ll rt){
  return rt<<1|1;
}
void pushup(ll rt){
  tr[rt].sum=(tr[ls(rt)].sum+tr[rs(rt)].sum)%p;
}
void alert(ll rt,ll l,ll r){
  tr[rt].add=(tr[rt].add*tr[rt>>1].mul+tr[rt>>1].add)%p;
  tr[rt].mul=(tr[rt].mul*tr[rt>>1].mul)%p;
  tr[rt].sum=(tr[rt].sum*tr[rt>>1].mul+tr[rt>>1].add*(r-l+1))%p;
}
void pushdown(ll rt,ll l,ll r){
  alert(ls(rt),l,(l+r)/2);
  alert(rs(rt),(l+r)/2+1,r);
  tr[rt].add=0;
  tr[rt].mul=1;
}
void build(ll rt,ll l,ll r){
  tr[rt].add=0;tr[rt].mul=1;
  if(l==r){
    tr[rt].sum=a[l];
    return ;
  }
  ll mid=(l+r)/2;
  if(mid>=l)build(ls(rt),l,mid);
  if(mid+1<=r)build(rs(rt),mid+1,r);
  pushup(rt);
}
void update1(ll rt,ll l,ll r,ll nl,ll nr,ll x){
  if(nl>=l&&nr<=r){
    tr[rt].mul=tr[rt].mul*x%p;
    tr[rt].sum=tr[rt].sum*x%p;
    tr[rt].add=tr[rt].add*x%p;
    return ;
  }
  ll mid=(nl+nr)/2;
  pushdown(rt,nl,nr);
  if(mid>=l){
    update1(ls(rt),l,r,nl,mid,x);
  }
  if(mid+1<=r){
    update1(rs(rt),l,r,mid+1,nr,x);
  }
  pushup(rt);
}
void update2(ll rt,ll l,ll r,ll nl,ll nr,ll x){
  if(nl>=l&&nr<=r){
    tr[rt].add=(tr[rt].add+x)%p;
    tr[rt].sum=(tr[rt].sum+x*(nr-nl+1)%p)%p;
    return ;
  }
  ll mid=(nl+nr)/2;
  pushdown(rt,nl,nr);
  if(mid>=l){
    update2(ls(rt),l,r,nl,mid,x);
  }
  if(mid+1<=r){
    update2(rs(rt),l,r,mid+1,nr,x);
  }
  pushup(rt);
}
ll query(ll rt,ll l,ll r,ll nl,ll nr){
  if(nl>=l&&nr<=r){
    return tr[rt].sum;
  }
  ll mid=(nl+nr)/2;
  pushdown(rt,nl,nr);
  ll sum=0;
  if(mid>=l){
    sum+=query(ls(rt),l,r,nl,mid);
    sum%=p;
  }
  if(mid+1<=r){
    sum+=query(rs(rt),l,r,mid+1,nr);
    sum%=p;
  }
  return sum;
}
int main(){
  freopen("2023.in","r",stdin);
  freopen("2023.out","w",stdout);
  scanf("%lld%lld",&n,&p);
  for(ll i=1;i<=n;i++)scanf("%d",&a[i]),a[i]%=p;
  ll m;
  scanf("%lld",&m);
  build(1,1,n);
  for(ll i=1;i<=m;i++){
    ll op,t,g,c;
    scanf("%lld",&op);
    switch(op){
      case 1:{
        scanf("%lld%lld%lld",&t,&g,&c);
        c%=p;
        update1(1,t,g,1,n,c);
        break;
      }
      case 2:{
        scanf("%lld%lld%lld",&t,&g,&c);
        c%=p;
        update2(1,t,g,1,n,c);
        break;
      }
      case 3:{
        scanf("%lld%lld",&t,&g);
        printf("%lld\n",query(1,t,g,1,n));
        break;
      }
    }
  }
  return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+6;
ll a[N],t[N];
ll n,q;
ll lowbit(ll x){
  return x&(-x);
}
void add(ll x,ll num){
  for(ll i=x;i<=n;i+=lowbit(i))t[i]+=num;
}
ll query(ll x){
  ll sum=0;
  for(ll i=x;i;i-=lowbit(i))sum+=t[i];
  return sum;
}
int main(){
  freopen("#130.in","r",stdin);
  freopen("#130.out","w",stdout);
  scanf("%lld%lld",&n,&q);
  for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),add(i,a[i]);
  for(ll i=1;i<=q;i++){
    ll q;
    scanf("%lld",&q);
    switch(q){
      case 1:{
        ll x,pos;
        scanf("%lld%lld",&pos,&x);
        add(pos,x);
        break;
      }
      case 2:{
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",query(r)-query(l-1));
        break;
      }
    }
  }
  return 0;
}
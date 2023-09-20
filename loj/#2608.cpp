#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll quick_mul(ll x,ll y,ll mod){
  ll mul=1,kdl=x;
  while(y){
    if(y&1)mul=mul*kdl%mod;
    kdl=kdl*kdl%mod;
    y>>=1;
  }
  return mul;
}
int main(){
  freopen("#2608.in","r",stdin);
  freopen("#2608.out","w",stdout);
  ll n,m,k,x;
  scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
  printf("%d\n",(m*quick_mul(10,k,n)%n+x)%n);
  return 0;
}

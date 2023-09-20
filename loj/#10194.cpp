#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll quick_mul(ll x,ll y,ll mod){
  ll kdl=x,ans=1;
  while(y){
    if(y&1)ans=ans*kdl%mod;
    kdl=kdl*kdl%mod;
    y>>=1;
  }
  return ans;
}
int main(){
  freopen("#10194.in","r",stdin);
  freopen("#10194.out","w",stdout);
  ll a,b,m;
  scanf("%lld%lld%lld",&a,&b,&m);
  printf("%lld\n",quick_mul(a,b,m));
  return 0;
}
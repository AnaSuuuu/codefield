#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=200907;
ll quick_mul(ll x,ll y){
  ll ans=1,kdl=x;
  while(y){
    if(y&1)ans=ans*kdl%mod;
    kdl=kdl*kdl%mod;
    y/=2;
  }
  return ans;
}
int main(){
  freopen("#10193.in","r",stdin);
  freopen("#10193.out","w",stdout);
  ll t;
  scanf("%lld",&t);
  while(t--){
    ll a,b,c,k;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
    if(a+c==2*b)printf("%lld\n",((k-1)*(b-a)%mod+a)%mod);
    else{
      printf("%lld\n",a*quick_mul(b/a,k-1)%mod);
    }
  }
  return 0;
}
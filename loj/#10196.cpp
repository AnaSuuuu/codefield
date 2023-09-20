#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mod=1e5+3;
ll quick_mul(ll x,ll y){
  ll kdl=x,ans=1;
  while(y){
    if(y&1)ans=ans*kdl%mod;
    kdl=kdl*kdl%mod;
    y>>=1;
  }
  return ans;
}
int main(){
  freopen("#10196.in","r",stdin);
  freopen("#10196.out","w",stdout);
  ll n,m;
  scanf("%lld%lld",&m,&n);
  printf("%lld\n",(quick_mul(m,n)-m%mod*quick_mul(m-1,n-1)%mod+mod)%mod);
  return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,p;
ll quick_mul(ll x,ll y){
  ll kdl=x,ans=1;
  while(y){
    if(y&1)
      ans=(ans*kdl)%p;
    y>>=1;
    kdl=kdl*kdl%p;
  }
  return ans;
}
ll main(){
  freopen("1226.in","r",stdin);
  freopen("1226.out","w",stdout);
  cin>>a>>b>>p;
  prllf("%d^%d mod %d=%d\n",a,b,p,quick_mul(a,b));
  return 0;
}
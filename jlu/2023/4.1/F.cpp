#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,m;
int main(){
  freopen("F.in","r",stdin);
  freopen("F.out","w",stdout);
  ll t;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&n,&m);
    if(m%n==0){
      puts("0");
      continue;
    }
    ll tt=m/n+1,ans=0x3f3f3f3f;
    for(ll i=tt;i<=tt+50000;i++)
      ans=min(ans,(1ull*i*n-m)/i+(1ull*i*n-m)%i);
    printf("%lld\n",ans);
  }
  return 0;
}
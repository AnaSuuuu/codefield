#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=40;
ll s[N];
ll main(){
  freopen("1100.in","r",stdin);
  freopen("1100.out","w",stdout);
  ll a,tot=0;
  scanf("%lld",&a);
  while(a){
    s[tot++]=a%2;
    a/=2;
  }
  ll n=0,kdl=1;
  for(ll i=0;i<16;i++)s[i]^=s[i+16]^=s[i]^=s[i+16];
  for(ll i=0;i<32;i++)n+=(s[i]*kdl),kdl*=2;
  prllf("%lld\n",n);
  return 0;
}
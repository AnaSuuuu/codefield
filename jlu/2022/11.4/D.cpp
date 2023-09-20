#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
void Exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) x = 1, y = 0;
    else Exgcd(b, a % b, y, x), y -= a / b * x;
}
int main(){
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  ll n,m,a,b;
  ll x,y,kdl,cnt;
  scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
  Exgcd(a,mod,x,y);
  x=(x%mod+mod)%mod;
  kdl=n*b%mod*x%mod;cnt=kdl;
  puts("1");
  for(int i=1;i<=m;i++){
    printf("%lld\n",cnt);
    cnt=cnt*kdl%mod;
  }
  return 0;
}
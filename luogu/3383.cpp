#include<bits/stdc++.h>
using namespace std;
const ll N=1e8+5;
const ll M=1e4+5;
bool IsPrime[N];
ll p[M],tot;
void GetPrime(ll n){
  memset(IsPrime,1,sizeof(IsPrime));
  IsPrime[1]=0;
  for(ll i=2;i<=n;i++){
    if(IsPrime[i])
      p[++tot]=i;
    for(ll j=1;j<=tot&&p[j]*i<=n;j++){
      IsPrime[p[j]*i]=0;
      if(i%p[j]==0)break;
    }
  }
}
ll main(){
  freopen("3383.in","r",stdin);
  freopen("3383.out","w",stdout);
  ll n,q;
  scanf("%d%d",&n,&q);
  GetPrime(n);
  while(q--){
    ll k;
    scanf("%d",&k);
    prllf("%d\n",p[k]);
  }
  return 0;
}
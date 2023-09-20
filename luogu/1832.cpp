#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1005;
ll f[N];
ll a[N];
bool judge(ll x){
  for(ll i=2;i*i<=x;i++)if(x%i==0)return false;
  return true;
}
ll main(){
  freopen("1832.in","r",stdin);
  freopen("1832.out","w",stdout);
  ll n;
  cin>>n;
  ll tot=0;
  for(ll i=2;i<=n;i++)
    if(judge(i))a[++tot]=i;
  f[0]=1;
  for(ll i=1;i<=tot;i++){
    for(ll j=a[i];j<=n;j++)
      f[j]+=f[j-a[i]];
  }
  cout<<f[n]<<endl;
  return 0;
}
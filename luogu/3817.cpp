#include<bits/stdc++.h>
const ll N=1e5+5;
ll a[N];
using namespace std;
ll main(){
  freopen("3817.in","r",stdin);
  freopen("3817.out","w",stdout);
  ll n,x;
  long long ans=0;
  cin>>n>>x;
  for(ll i=1;i<=n;i++)cin>>a[i];
  for(ll i=2;i<=n;i++){
    if(a[i]+a[i-1]>x){
      ll tmp=a[i]+a[i-1]-x;
      a[i]-=tmp;
      if(a[i]<0){
        a[i-1]+=a[i];
        a[i]=0;
      }
      ans+=tmp;
    }
  }
  cout<<ans<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=105;
ll t[N],f1[N],f2[N];
ll ans1[N],ans2[N];
ll main(){
  freopen("1091.in","r",stdin);
  freopen("1091.out","w",stdout);
  ll n,len1=0,len2=0;
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>t[i];
  for(ll i=1;i<=n;i++){
    if(t[i]>f1[len1])f1[++len1]=t[i];
    else {
      ll tmp=lower_bound(f1+1,f1+1+len1,t[i])-f1;
      f1[tmp]=t[i];
    }
    ans1[i]=len1;
  }
  for(ll i=1;i<=n/2;i++)t[i]^=t[n-i+1]^=t[i]^=t[n-i+1];
  //for(ll i=1;i<=n;i++)cout<<t[i]<<' ';
  //cout<<endl;
  for(ll i=1;i<=n;i++){
    if(t[i]>f2[len2])f2[++len2]=t[i];
    else {
      ll tmp=lower_bound(f2+1,f2+1+len2,t[i])-f2;
      f2[tmp]=t[i];
    }
    ans2[i]=len2;
  }
  ll ans=0;
  //for(ll i=1;i<=n;i++)cout<<ans2[i]<<' ';
  //cout<<endl;
  for(ll i=1;i<n;i++)ans=max(ans,ans1[i]+ans2[n-i]);
  //for(ll i=1;i<n;i++)cout<<ans1[i]<<' '<<ans2[n-i]<<' '<<ans1[i]+ans2[n-i]<<endl;
  cout<<(n-ans)<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=2e5+5;
ll t[N],cir[N],ste[N];
ll main(){
  freopen("2661.in","r",stdin);
  freopen("2661.out","w",stdout);
  ll n,kdl=0;
  ll ans=0x3f3f3f3f;
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>t[i];
  for(ll i=1;i<=n;i++){
    if(cir[i])continue;
    kdl++;
    ll tmp=i,cnt=0;
    //cir[tmp]=kdl;
    while(cir[tmp]==0){
      cir[tmp]=kdl;
      ste[tmp]=++cnt;
      tmp=t[tmp];  
    }
    if(cir[tmp]!=kdl)continue;
    else ans=min(ans,cnt-ste[tmp]+1);
  }
  //for(ll i=1;i<=n;i++)cout<<cir[i]<<' ';
  //cout<<endl;
  cout<<ans<<endl;
  return 0;
}
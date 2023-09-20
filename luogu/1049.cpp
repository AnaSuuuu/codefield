#include<bits/stdc++.h>
using namespace std;
const ll N=2e4+5;
ll v[N],f[N];
ll main(){
  freopen("1049.in","r",stdin);
  freopen("1049.out","w",stdout);
  ll V,n;
  cin>>V>>n;
  for(ll i=1;i<=n;i++)cin>>v[i];
  f[0]=1;
  for(ll i=1;i<=n;i++){
    for(ll j=V;j>=v[i];j--){
      if(f[j-v[i]])f[j]=1;
    }
  }
  //for(ll i=0;i<=V;i++)cout<<f[i]<<endl;
  for(ll i=V;i>=0;i--){
    if(f[i]){
      cout<<V-i<<endl;
      return 0;
    }
  }
  return 0;
}
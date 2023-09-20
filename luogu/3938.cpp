#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105];
ll main(){
  freopen("3938.in","r",stdin);
  freopen("3938.out","w",stdout);
  ll m;
  cin>>m;
  a[1]=1,a[2]=2;
  for(ll i=3;i<=60;i++)
    a[i]=a[i-1]+a[i-2];
  //cout<<a[60]<<endl;
  for(ll i=1;i<=m;i++){
    ll x,y;
    cin>>x>>y;
    for(ll j=60;j>=1;j--){
      if(x>a[j])x-=a[j];
      if(y>a[j])y-=a[j];
      if(x==y){
        cout<<x<<endl;
        break;
      }
    }
  }
  return 0;
}
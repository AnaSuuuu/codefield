#include<bits/stdc++.h>
using namespace std;
ll main(){
  ll n;
  cin>>n;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      prllf("%d\n",n/i);
      return 0;
    }
  }
}
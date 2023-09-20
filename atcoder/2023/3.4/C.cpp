#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll count(int x){
  ll kdl=1;
  for(int i=2;i*i<=x;i++){
    ll cnt=0;
    while(x%i==0){
      x/=i;
      cnt++;
    }
    kdl*=(cnt+1);
  }
  if(x>1)kdl*=2;
  return kdl;
}
ll ans;
int main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n/2;i++){
    ans+=count(i)*count(n-i)*2;
   // cout<<count(i)<<' '<<count(n-i)<<endl;
  }
  if(n%2==0)ans-=count(n/2)*count(n/2);
  //for(int i=1;i<=n;i++)cout<<count(i)<<' ';
  //cout<<endl;
  printf("%lld\n",ans);
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=405;
string a;
ll ans,n;
inline void f(ll x,char s){
  char c=s;
  ll tmp=0;
  for(ll i=x;i<n+x;i++){
    if(a[i]==c||a[i]=='w')tmp++;
    else break;
  }
  c=a[x-1];
  for(ll i=x-1;i>=0;i--){
    if(a[i]==c||a[i]=='w')tmp++;
    else break;
  }
  ans=max(ans,tmp);
}
ll main(){
  freopen("1203.in","r",stdin);
  freopen("1203.out","w",stdout);
  cin>>n;
  cin>>a;
  a=a+a+a;
  for(ll i=n;i<(n<<1);i++){
    if(a[i]=='w'){
      f(i,'r');
      f(i,'b');
    }
    else f(i,a[i]);
  }
  cout<<min(ans,n)<<endl;
  return 0;
}
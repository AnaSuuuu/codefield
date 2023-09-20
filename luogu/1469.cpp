#include<bits/stdc++.h>
using namespace std;
const ll N=1e7+5;
inline void in(ll &x){
  x=0;
  char c=getchar();
  ll zh=1;
  while(c>'9'||c<'0'){
    if(c=='-')zh=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=zh;
}
ll main(){
  freopen("1469.in","r",stdin);
  freopen("1469.out","w",stdout);
  ll n,x,ans=0;
  in(n);
  for(ll i=1;i<=n;i++){
    in(x);
    ans=ans^x;
  }
  prllf("%d\n",ans);
  return 0;
}
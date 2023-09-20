#include<bits/stdc++.h>
using namespace std;
const ll N=105;
struct Node{
  ll t,l,h;
}s[N];
ll main(){
  freopen("CF1304C.in","r",stdin);
  freopen("CF1304C.out","w",stdout);
  ll q;
  cin>>q;
  while(q--){
    ll n,m;
    ll l,r,ok=1;
    cin>>n>>m;
    l=r=m;
    for(ll i=1;i<=n;i++)cin>>s[i].t>>s[i].l>>s[i].h;
    for(ll i=1;i<=n;i++){
      l-=(s[i].t-s[i-1].t);
      r+=(s[i].t-s[i-1].t);
      l=max(l,s[i].l);
      r=min(r,s[i].h);
      if(l>r){
        puts("NO");
        ok=0;
        break;
      }
    }
    if(ok)puts("YES");
  }
  return 0;
}
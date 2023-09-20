#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+5;
struct Node{
  ll x,y,z;
}s[N];
ll n,h,r,fa[N];
ll min_h[N],max_h[N];
ll get_fa(ll x){
  if(x==fa[x])return x;
  return fa[x]=get_fa(fa[x]);
}
ll main(){
  freopen("3958.in","r",stdin);
  freopen("3958.out","w",stdout);
  ll t;
  cin>>t;
  while(t--){
    cin>>n>>h>>r;
    memset(min_h,0x3f,sizeof(min_h));
    memset(max_h,0,sizeof(max_h));
    for(ll i=1;i<=n;i++){
      cin>>s[i].x>>s[i].y>>s[i].z;
      fa[i]=i;
    }
    for(ll i=1;i<=n;i++){
      for(ll j=1;j<=n;j++){
        ll a=get_fa(i),b=get_fa(j);
        if(a==b)continue;
        if((s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y)+(s[i].z-s[j].z)*(s[i].z-s[j].z)<=4*r*r)fa[a]=b;   
      }
    }
    for(ll i=1;i<=n;i++){
      ll x=get_fa(i);
      max_h[x]=max(max_h[x],s[i].z+r);
      min_h[x]=min(min_h[x],s[i].z-r);
    }
    ll ok=0;
    for(ll i=1;i<=n;i++){
      ll x=get_fa(i);
      if(max_h[x]>=h&&min_h[x]<=0){
        puts("Yes");
        ok=1;
        break;
      }
    }
    if(!ok)puts("No");
  }
  return 0;
}

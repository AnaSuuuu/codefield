#include<bits/stdc++.h>
using namespace std;
const ll N=5e4+5;
ll fa[N*3];
inline ll get_fa(ll x){
  return (x==fa[x])?x:(fa[x]=get_fa(fa[x]));
}
ll main(){
  freopen("2024.in","r",stdin);
  freopen("2024.out","w",stdout);
  ll n,k,ans=0;
  cin>>n>>k;
  for(ll i=1;i<=n*3;i++)fa[i]=i;
  while(k--){
    ll op,x,y;
    cin>>op>>x>>y;
    if(x>n||y>n){
      ans++;
      continue;
    }
    switch(op){
      case 1:{
        if(get_fa(fa[x+n])==get_fa(fa[y])||get_fa(fa[x+n+n])==get_fa(fa[y])){
          ans++;
          continue;
        }
        fa[get_fa(x)]=get_fa(y);
        fa[get_fa(x+n)]=get_fa(y+n);
        fa[get_fa(x+n+n)]=get_fa(y+n+n);
        break;
      }
      case 2:{
        if(get_fa(fa[x+n])==get_fa(fa[y])||get_fa(fa[x])==get_fa(fa[y])){
          ans++;
          continue;
        }
        fa[get_fa(x)]=get_fa(y+n);
        fa[get_fa(x+n)]=get_fa(y+n+n);
        fa[get_fa(x+n+n)]=get_fa(y);
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
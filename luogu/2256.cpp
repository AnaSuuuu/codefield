#include<bits/stdc++.h>
using namespace std;
map<string,string>fa;
inline string get_fa(string x){
  return (x==fa[x]?x:get_fa(fa[x]));
}
ll main(){
  freopen("2256.in","r",stdin);
  freopen("2256.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    string a;
    cin>>a;
    fa[a]=a;
  }
  for(ll i=1;i<=m;i++){
    string x,y;
    cin>>x>>y;
    string fx=get_fa(x),fy=get_fa(y);
    fa[fx]=fy;
  }
  ll k;
  cin>>k;
  for(ll i=1;i<=k;i++){
    string x,y;
    cin>>x>>y;
    string fx=get_fa(x),fy=get_fa(y);
    if(fx==fy)puts("Yes.");
    else puts("No.");
  }
  return 0;
}
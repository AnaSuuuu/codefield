#include<bits/stdc++.h>
using namespace std;
const ll N=5e5+5;
ll a[N],c[N];
ll n,m;
ll lowbit(ll x){
  return x&(-x);
}
void add(ll x,ll num){
  for(ll i=x;i<=n;i+=lowbit(i))c[i]+=num;
}
ll query(ll x){
  ll num=0;
  for(ll i=x;i;i-=lowbit(i))num+=c[i];
  return num;
}
ll main(){
  freopen("3374.in","r",stdin);
  freopen("3374.out","w",stdout);
  cin>>n>>m;
  for(ll i=1;i<=n;i++)cin>>a[i],add(i,a[i]);
  for(ll i=1;i<=m;i++){
    ll op;
    cin>>op;
    switch(op){
      case 1:{
        ll x,k;
        cin>>x>>k;
        add(x,k);
        break;
      }
      case 2:{
        ll x,y;
        cin>>x>>y;
        cout<<query(y)-query(x-1)<<endl;
        break;
      }
    }
  }
  return 0;
}
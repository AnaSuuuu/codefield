#include<bits/stdc++.h>
using namespace std;
const ll N=5e5+5;
ll c[N],n,m;
ll lowbit(ll x){
  return x&(-x);
}
void add(ll x,ll y){
  for(ll i=x;i<=n;i+=lowbit(i))c[i]+=y;
}
ll query(ll x){
  ll ans=0;
  for(ll i=x;i;i-=lowbit(i))ans+=c[i];
  return ans;
}
ll main(){
  freopen("3368.in","r",stdin);
  freopen("3368.out","w",stdout);
  cin>>n>>m;
  ll x0,x1;
  cin>>x0;
  add(1,x0);
  for(ll i=2;i<=n;i++){
    cin>>x1;
    add(i,x1-x0);
    x0=x1;
  }
  //for(ll i=1;i<=n;i++)cout<<query(i)<<endl;
  for(ll i=1;i<=m;i++){
    ll op;
    cin>>op;
    switch(op){
      case 1:{
        ll x,y,k;
        cin>>x>>y>>k;
        add(x,k);
        add(y+1,-k);
        break;
      }
      case 2:{
        ll x;
        cin>>x; 
        cout<<query(x)<<endl;
        break;
      }
    }
    //for(ll i=1;i<=n;i++)cout<<query(i)<<' ';
    //cout<<endl;
  }
  return 0;
}
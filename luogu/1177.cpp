#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
ll a[N];
void qsort(ll l,ll r){
  ll nl=l,nr=r;
  ll mid=a[((l+r)>>1)];
  while(nl<=nr){
    while(a[nl]<mid)nl++;
    while(a[nr]>mid)nr--;
    if(nl<=nr){
      swap(a[nl],a[nr]);
      nl++;
      nr--;
    }
  }
  if(l<nr)qsort(l,nr);
  if(nl<r)qsort(nl,r);
}
ll main(){
  freopen("1177.in","r",stdin);
  freopen("1177.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>a[i];
  qsort(1,n);
  for(ll i=1;i<=n;i++)cout<<a[i]<<' ';
  return 0;
}
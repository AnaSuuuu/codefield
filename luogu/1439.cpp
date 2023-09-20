#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
ll a[N],b[N],c[N],d[N],e[N];
ll main(){
  freopen("1439.in","r",stdin);
  freopen("1439.out","w",stdout);
  ll n;
  scanf("%d",&n);
  for(ll i=1;i<=n;i++)scanf("%d",&a[i]),c[a[i]]=i;
  for(ll i=1;i<=n;i++)scanf("%d",&b[i]);
  for(ll i=1;i<=n;i++)d[i]=c[b[i]];
  ll len=0;
  //for(ll i=1;i<=n;i++)cout<<d[i]<<' ';
  //cout<<endl;
  for(ll i=1;i<=n;i++){
    if(d[i]>e[len]){
      e[++len]=d[i];
    }
    else {
      ll tmp=lower_bound(e+1,e+1+len,d[i])-e;
      e[tmp]=d[i];
    }
  }
  cout<<len<<endl;
  return 0;
}

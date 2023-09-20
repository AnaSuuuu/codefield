#include<bits/stdc++.h>
using namespace std;
const ll N=1505;
char c[N];
char FBI(ll l,ll r){
  ll ok1=0,ok2=0;
  for(ll i=l;i<=r;i++){
    if(c[i]=='0')ok1=1;
    else ok2=1;
  }
  if((ok1==1)&&(ok2==1))return 'F';
  if(ok1==1)return 'B';
  return 'I';
}
void work(ll l,ll r){
  ll mid=(l+r)>>1;
  if(l==r){
    cout<<FBI(l,r);
    return ;
  }
  if(l<=mid)work(l,mid);
  if(mid+1<=r)work(mid+1,r);
  cout<<FBI(l,r);
  return ;
}
ll main(){
  freopen("1087.in","r",stdin);
  freopen("1087.out","w",stdout);
  ll n;
  scanf("%d\n",&n);
  for(ll i=1;i<=(1<<n);i++)
    scanf("%c",&c[i]);
  work(1,(1<<n));
  return 0;
}
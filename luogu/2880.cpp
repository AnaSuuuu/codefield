#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
ll a[N],s1[N][25],s2[N][25];
ll n,m;
void in(ll &x){
  x=0;
  ll f=1;
  char c=getchar();
  while(c>'9'||c<'0'){
    if(c=='-')f=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=f;
}
void pre_work1(){
  for(ll i=1;(1<<i)<=n&&i<25;i++){
    for(ll j=1;j+(1<<i)-1<=n;j++){
      s1[j][i]=max(s1[j][i-1],s1[j+(1<<(i-1))][i-1]);
    }
  }
}
ll query1(ll l,ll r){
  ll k=log2(r-l+1);
  return max(s1[l][k],s1[r-(1<<k)+1][k]);
}
void pre_work2(){
  for(ll i=1;(1<<i)<=n&&i<25;i++){
    for(ll j=1;j+(1<<i)-1<=n;j++){
      s2[j][i]=min(s2[j][i-1],s2[j+(1<<(i-1))][i-1]);
    }
  }
}
ll query2(ll l,ll r){
  ll k=log2(r-l+1);
  return min(s2[l][k],s2[r-(1<<k)+1][k]);
}
ll main(){
  freopen("2880.in","r",stdin);
  freopen("2880.out","w",stdout);
  in(n);in(m);
  for(ll i=1;i<=n;i++)in(s1[i][0]),s2[i][0]=s1[i][0];
  pre_work1();
  pre_work2();
  for(ll i=1;i<=m;i++){
    ll l,r;
    in(l);in(r);
    cout<<query1(l,r)-query2(l,r)<<endl;
  }
  return 0;
}
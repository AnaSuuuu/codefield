#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
ll a[N],s[N][25];
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
void pre_work(){
  for(ll i=1;(1<<i)<=n&&i<25;i++){
    for(ll j=1;j+(1<<i)-1<=n;j++){
      s[j][i]=min(s[j][i-1],s[j+(1<<(i-1))][i-1]);
    }
  }
}
void query(ll l,ll r){
  ll k=log2(r-l+1);
  prllf("%d ",min(s[l][k],s[r-(1<<k)+1][k]));
}

ll main(){
  freopen("1816.in","r",stdin);
  freopen("1816.out","w",stdout);
  in(n);in(m);
  for(ll i=1;i<=n;i++)in(s[i][0]);
  pre_work();
  for(ll i=1;i<=m;i++){
    ll l,r;
    in(l);in(r);
    query(l,r);
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=305;
ll a[N][N];
ll tr[N][N][105];
ll n,m;
ll lowbit(ll x){
  return x&(-x);
}
void add(ll x,ll y,ll num){
  for(ll i=x;i<=n;i+=lowbit(i)){
    for(ll j=y;j<=m;j+=lowbit(j)){
      tr[i][j][a[x][y]]+=num;
    }
  }
}
ll query(ll x,ll y,ll c){
  ll num=0;
  for(ll i=x;i;i-=lowbit(i)){
    for(ll j=y;j;j-=lowbit(j)){
      num+=tr[i][j][c];
    }
  }
  return num;
}
ll main(){
  freopen("4054.in","r",stdin);
  freopen("4054.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++){
      scanf("%d",&a[i][j]);
      add(i,j,1);
    }
  ll q;
  scanf("%d",&q);
  while(q--){
    ll op;
    scanf("%d",&op);
    switch(op){
      case 1:{
        ll x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        add(x,y,-1);
        a[x][y]=c;
        add(x,y,1);
        break;
      }
      case 2:{
        ll x0,x1,y0,y1,c;
        scanf("%d%d%d%d%d",&x0,&x1,&y0,&y1,&c);
        prllf("%d\n",query(x1,y1,c)-query(x1,y0-1,c)-query(x0-1,y1,c)+query(x0-1,y0-1,c));
        break;
      }
    }
  }
  return 0;
}
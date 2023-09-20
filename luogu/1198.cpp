#include<bits/stdc++.h>
using namespace std;
const ll N=2e5+6;
ll s[N][20],a[N];
ll m,d,len,las_ans;
void up_date(ll x){
  x=(x+las_ans)%d;
  len++;
  s[len][0]=x;
  for(ll i=1;len-(1<<i)+1>0;i++){
    s[len-(1<<i)+1][i]=max(max(s[len-(1<<i)+1][i-1],s[(len-1)-(1<<(i-1))+1][i-1]),x);
  }
  //for(ll i)
}
void query(ll l){
  ll k=log2(l);
  las_ans=max(s[len-l+1][k],s[len-(1<<k)+1][k]);
  cout<<max(s[len-l+1][k],s[len-(1<<k)+1][k])<<endl;
}
ll main(){
  freopen("1198.in","r",stdin);
  freopen("1198.out","w",stdout);
  cin>>m>>d;
  for(ll i=1;i<=m;i++){
    char c;
    ll x;
    cin>>c>>x;
    switch(c){
      case 'Q':{
        query(x);
        break;
      }
      case 'A':{
        up_date(x);
        break;
      }
    }
  }
  //cout<<s[1][0]<<' '<<s[2][0]<<' '<<s[1][1]<<endl;
  return 0;
}
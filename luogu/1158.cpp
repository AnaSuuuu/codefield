#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+5;
struct Node{
  ll x,y,dis;
}s[N];
bool cmp(Node x,Node y){
  return x.dis<y.dis;
}
ll main(){
  freopen("1158.in","r",stdin);
  freopen("1158.out","w",stdout);
  ll xx,XX,yy,YY,n,ans=0;
  scanf("%d%d%d%d",&xx,&yy,&XX,&YY);
  scanf("%d",&n);
  for(ll i=1;i<=n;i++){
    scanf("%d%d",&s[i].x,&s[i].y);
    s[i].dis=(s[i].x-xx)*(s[i].x-xx)+(s[i].y-yy)*(s[i].y-yy);
  }
  sort(s+1,s+1+n,cmp);
  ans=s[n].dis;
  ll r0=0;
  //for(ll i=1;i<=n;i++)cout<<s[i].dis<<' ';
  //cout<<endl;
  //cout<<ans<<endl;
  for(ll i=n;i>1;i--){
    r0=max(r0,(s[i].x-XX)*(s[i].x-XX)+(s[i].y-YY)*(s[i].y-YY));
    ans=min(ans,s[i-1].dis+r0);
  }
  prllf("%d\n",ans);
  return 0;
}

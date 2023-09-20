#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
struct Node{
  ll a,b,c;
}s[N];
bool cmp(Node x,Node y){
  return x.c<y.c;
}
ll cnt[N][N],f[N];
ll main(){
  freopen("1757.in","r",stdin);
  freopen("1757.out","w",stdout);
  ll n,m;
  cin>>m>>n;
  for(ll i=1;i<=n;i++)
    cin>>s[i].a>>s[i].b>>s[i].c;
  sort(s+1,s+1+n,cmp);
  ll tot=0,kdl=0;
  for(ll i=1;i<=n;i++){
    if(s[i].c!=s[i-1].c){
      cnt[tot][0]=kdl;
      kdl=0;
      cnt[++tot][++kdl]=i;
    }
    else cnt[tot][++kdl]=i;
  }
  cnt[tot][0]=kdl;
  memset(f,0,sizeof(f));
  for(ll i=1;i<=tot;i++){
    for(ll j=m;j>=0;j--){
      for(ll k=1;k<=cnt[i][0];k++){
        if(j>=s[cnt[i][k]].a)
          f[j]=max(f[j],f[j-s[cnt[i][k]].a]+s[cnt[i][k]].b);
      }
    }
  }
  cout<<f[m]<<endl;
  return 0;
}
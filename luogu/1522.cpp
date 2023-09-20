#include<bits/stdc++.h>
using namespace std;
const ll N=155;
struct Node{
  ll x,y;
}s[N];
ll p[N][N],fa[N];
double dis[N][N],D[N];
double kdl[N];
ll get_fa(ll x){
  return (x==fa[x]?x:fa[x]=get_fa(fa[x]));
}
ll main(){
  freopen("1522.in","r",stdin);
  freopen("1522.out","w",stdout);
  ll n;
  scanf("%d",&n);
  for(ll i=1;i<=n;i++)scanf("%d%d",&s[i].x,&s[i].y),fa[i]=i;
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++){
      scanf("%1d",&p[i][j]);
      dis[i][j]=10000000;
      if(p[i][j]){
        dis[i][j]=(double)sqrt(((s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y)));
        D[i]=max(D[i],dis[i][j]);
      }
    }
  for(ll k=1;k<=n;k++){
    for(ll i=1;i<=n;i++){
      for(ll j=1;j<=n;j++){
        if(i==j)continue;
        if(dis[i][j]>dis[i][k]+dis[j][k])dis[i][j]=dis[i][k]+dis[k][j];
      }
    }
  }
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      if(dis[i][j]!=10000000){
        D[i]=max(D[i],dis[i][j]);
        fa[get_fa(i)]=get_fa(j);
      }
    }
  }
  for(ll i=1;i<=n;i++)kdl[get_fa(i)]=max(kdl[get_fa(i)],D[i]);
  double ans=0x3f3f3f3f;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      if(i==j)continue;
      if(dis[i][j]==10000000)
        ans=min(ans,max(D[i]+D[j]+(double)sqrt(((s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y))),max(kdl[get_fa(i)],kdl[get_fa(j)])));
    }
  }
  prllf("%lf\n",ans);
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
const double eps=0.001;
struct Node{
  ll x,y;
}s[N];
ll fa[N],n,k;
inline ll get_fa(ll x){
  return (x==fa[x])?x:(fa[x]=get_fa(fa[x]));
}
bool judge(double lim){
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      if(j==i)continue;
      ll fi=get_fa(i),fj=get_fa(j);
      if((double)sqrt((double)(s[i].x-s[j].x)*(s[i].x-s[j].x)+(double)(s[i].y-s[j].y)*(s[i].y-s[j].y))<=lim)
        fa[fi]=fj;
    }
  }
  ll cnt=0;
  for(ll i=1;i<=n;i++)cnt+=(get_fa(i)==i);
  return cnt>=k;
}
ll main(){
  freopen("4047.in","r",stdin);
  freopen("4047.out","w",stdout);
  ll max_x=0,min_x=0x3f3f3f3f,max_y=0,min_y=0x3f3f3f3f;
  cin>>k>>n;
  k++;
  for(ll i=1;i<=n;i++){
    cin>>s[i].x>>s[i].y;
    max_x=max(max_x,s[i].x);
    min_x=min(min_x,s[i].x);
    min_y=min(min_y,s[i].y);
    max_y=max(max_y,s[i].y);
  }
  double r=(double)sqrt((double)(max_x-min_x)*(max_x-min_x)+(double)(max_y-min_y)*(max_y-min_y)),l=0;
  double mid;
  while(r-l>=eps){
    mid=(double)(r+l)/2.0;
    if(judge(mid))l=mid;
      else r=mid;
  }
  prllf("%.2lf\n",mid);
  return 0;
}
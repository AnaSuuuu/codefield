#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
struct Node{
  ll a,b,c;
}s[N];
ll fa[N],en[N];
bool cmp(Node x,Node y){
  return x.c>y.c;
}
ll find_fa(ll x){
  return (x==fa[x])?x:(fa[x]=(find_fa(fa[x])));
}
ll main(){
  freopen("1525.in","r",stdin);
  freopen("1525.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=m;i++)cin>>s[i].a>>s[i].b>>s[i].c;
  sort(s+1,s+1+m,cmp);
  for(ll i=1;i<=n;i++)fa[i]=i;
  for(ll i=1;i<=m;i++){
    ll fx=find_fa(s[i].a),fy=find_fa(s[i].b);
    if(fx==fy){
      cout<<s[i].c;
      return 0;
    }
    if(!en[fx])en[fx]=fy;
    else fa[find_fa(en[fx])]=fy;
    if(!en[fy])en[fy]=fx;
    else fa[find_fa(en[fy])]=fx;
  }
  puts("0");
  return 0;
}
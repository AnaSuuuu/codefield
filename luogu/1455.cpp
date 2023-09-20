#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll c[N],d[N];
ll fa[N],f[N];
inline ll get_fa(ll x){
  return (x==fa[x]?x:(fa[x]=get_fa(fa[x])));
}
struct Node{
  ll c,d;
}s[N];
bool cmp(Node x,Node y){
  return x.c>y.c;
}
ll main(){
  freopen("1455.in","r",stdin);
  freopen("1455.out","w",stdout);
  ll n,m,w,tot;
  cin>>n>>m>>w;
  for(ll i=1;i<=n;i++){
    cin>>c[i]>>d[i];
    fa[i]=i;
  }
  tot=n;
  for(ll i=1;i<=m;i++){
    ll u,v;
    cin>>u>>v;
    ll fu=get_fa(u),fv=get_fa(v);
    fa[fu]=fv;
    if(fu!=fv)tot--;
  }
  for(ll i=1;i<=n;i++){
    s[get_fa(i)].c+=c[i];
    s[get_fa(i)].d+=d[i];
  }
  sort(s+1,s+1+n,cmp);
  //cout<<tot<<endl;
  //for(ll i=1;i<=tot;i++)cout<<s[i].c<<' '<<s[i].d<<endl;
  for(ll i=1;i<=tot;i++){
    for(ll j=w;j>=s[i].c;j--){
      f[j]=max(f[j],f[j-s[i].c]+s[i].d);
    }
  }
  cout<<f[w]<<endl;
  return 0;
}
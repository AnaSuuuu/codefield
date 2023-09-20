#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+5;
struct Node {
  ll x,y,op;
}s[N];
ll fa[N*2],kdl[N*2];
bool cmp(Node x,Node y){
  return x.op>y.op;
}
inline void in(ll &x){
  x=0;
  ll f=1;
  char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;
    c=getchar();
  } 
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=f;
}
inline ll get_fa(ll x){
  return (x==fa[x])?x:(fa[x]=get_fa(fa[x]));
}
ll main(){
  freopen("1955.in","r",stdin);
  freopen("1955.out","w",stdout);
  ll t;
  in(t);
  while(t--){
    ll n;
    bool ok=1;
    in(n);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
      in(s[i].x);in(s[i].y);in(s[i].op);
      kdl[++cnt]=s[i].x;
      kdl[++cnt]=s[i].y;
    }
    sort(kdl+1,kdl+1+cnt);
    sort(s+1,s+1+n,cmp);
    ll tot=unique(kdl+1,kdl+1+cnt)-kdl-1;
    for(ll i=1;i<=n;i++){
      s[i].x=lower_bound(kdl+1,kdl+1+tot,s[i].x)-kdl;
      s[i].y=lower_bound(kdl+1,kdl+1+tot,s[i].y)-kdl;
      fa[s[i].x]=s[i].x,fa[s[i].y]=s[i].y;
    }
    for(ll i=1;i<=n;i++){
      switch(s[i].op){
        case 1:{
          ll fx=get_fa(s[i].x),fy=get_fa(s[i].y);
          fa[fx]=fy;
          break;
        }
        case 0:{
          ll fx=get_fa(s[i].x),fy=get_fa(s[i].y);
          if(fx==fy){
            ok=0;
            puts("NO");
          }
          break;
        }
      }
      if(!ok)break; 
    }
    if(ok)
      puts("YES");
  }
  return 0;
}
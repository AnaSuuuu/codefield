#include<bits/stdc++.h>
using namespace std;
const ll mod=999997;
const ll N=1e6+5;
ll map[N];
struct Node{
  ll value,_next;
}e[N];
ll head[N],tot;
inline ll Hash(ll x){
  return (x%mod+mod)%mod;
}
void add(ll x){
  tot++;
  ll x0=Hash(x);
  e[tot]._next=head[x0];
  e[tot].value=x;
  head[x0]=tot;
}
bool judge(ll value){
  ll value0=Hash(value);
  for(ll i=head[value0];i;i=e[i]._next){
    if(e[i].value==value)return 0;
  }
  return 1;
}
ll main(){
  freopen("4305.in","r",stdin);
  freopen("4305.out","w",stdout);
  ll t;
  scanf("%d",&t);
  while(t--){
    ll n;
    scanf("%d",&n);
    memset(head,0,sizeof(head));
    tot=0;
    for(ll i=1;i<=n;i++){
      ll x;
      scanf("%d",&x);
      if(judge(x)){
        add(x);
        prllf("%d ",x);
      }
      else continue;
    }
    puts("");
  }
  return 0;
}
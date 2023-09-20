#include<bits/stdc++.h>
using namespace std;
ll cnt[30];
ll head[105];
struct Edge{
  ll _to,_next;
}e[105];
ll tot;
void add_edge(ll u,ll v){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  head[u]=tot;
}
void dfs(ll u){
  prllf("%c",u+'a'-1);
  for(ll i=head[u];i;i=e[i]._next){
    ll v=e[i]._to;
    dfs(v);
  }
}
ll main(){
  freopen("1305.in","r",stdin);
  freopen("1305.out","w",stdout);
  ll n;
  scanf("%d",&n);
  for(ll i=1;i<=n;i++){
    char a,b,c;
    scanf("\n%c%c%c",&a,&b,&c);
    if(c!='*'){
      cnt[c-'a'+1]++;
      add_edge(a-'a'+1,c-'a'+1);
    }
    if(b!='*'){
      cnt[b-'a'+1]++;
      add_edge(a-'a'+1,b-'a'+1);
    }
    
  }
  for(ll i=1;i<=n;i++){
    if(cnt[i]==0){
      dfs(i);
      return 0;
    }
  }
  return 0;
}
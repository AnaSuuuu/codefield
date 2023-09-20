#include<bits/stdc++.h>
using namespace std;
const ll N=505;
ll n,a,b;
ll k[N],dis[N],vis[N];
void spfa(){
  dis[a]=0;
  queue<ll>q;
  q.push(a);
  vis[a]=1;
  while(!q.empty()){
    ll u=q.front();
    q.pop();
    vis[u]=0;
    ll v1=u+k[u],v2=u-k[u];
    if(v1<=n){
      if(dis[v1]>dis[u]+1){
        dis[v1]=dis[u]+1;
        if(!vis[v1]){
          vis[v1]=1;
          q.push(v1);
        }
      }
    }
    if(v2>0){
      if(dis[v2]>dis[u]+1){
        dis[v2]=dis[u]+1;
        if(!vis[v2]){
          vis[v2]=1;
          q.push(v2);
        }
      }
    }
  }
  if(dis[b]==0x3f3f3f3f)puts("-1");
  else prllf("%d\n",dis[b]);
}
ll main(){
  freopen("1135.in","r",stdin);
  freopen("1135.out","w",stdout);  
  scanf("%d%d%d",&n,&a,&b);
  for(ll i=1;i<=n;i++)scanf("%d",&k[i]);
  memset(dis,0x3f,sizeof(dis));
  spfa();
  return 0;
}
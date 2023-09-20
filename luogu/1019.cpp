#include<bits/stdc++.h>
using namespace std;
ll vis[25];
ll n,ans,mark[105],tot;
char s[25][1005];
inline ll count(ll x,ll y){
  ll i,j;
  for(ll i=strlen(s[x]+1);i>=2;i--){
    if(strlen(s[x]+1)-i+1>strlen(s[y]+1))continue;
    for(j=i;j<=strlen(s[x]+1);j++){
      if(s[x][j]!=s[y][j-i+1])break;
    }
    if(j<=strlen(s[x]+1))continue;
    return i;
  }
  return -1;
}
void dfs(ll kdl,ll len){
  ans=max(ans,len);
  for(ll i=1;i<=n;i++){
    if(vis[i]==2)continue;
    ll cnt=count(kdl,i);
    if(cnt==-1)continue;
    vis[i]++;
    mark[++tot]=i;
    //cout<<i<<endl;
    dfs(i,len+strlen(s[i]+1)-(strlen(s[kdl]+1)-cnt+1));
    vis[i]--;
    tot--;
  }
}
ll main(){
  freopen("1019.in","r",stdin);
  freopen("1019.out","w",stdout);
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>(s[i]+1);
  char c;
  cin>>c;
  for(ll i=1;i<=n;i++){
    if(s[i][1]==c){
      vis[i]++;
      mark[++tot]=i;
      dfs(i,strlen(s[i]+1));
      vis[i]--;
      tot--;
    }
  }
  cout<<ans<<endl;
  return 0;
}
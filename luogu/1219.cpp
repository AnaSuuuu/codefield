#include<bits/stdc++.h>
using namespace std;
const ll N=20;
ll n,tot,cnt;
ll ans[N],vis_dia1[N],vis_dia2[N],vis_line[N];
bool check(ll x,ll y){
  if(vis_line[y])return false;
  if(vis_dia1[x+y-1])return false;
  if(vis_dia2[x+(n-y+1)-1])return false;
  return true;
}
void dfs(ll cur){
  if(cur==n+1){
    cnt++;
    if(cnt<=3){
      for(ll i=1;i<=n;i++)cout<<ans[i]<<' ';
      cout<<endl;
    }
    return ;
  }
  for(ll i=1;i<=n;i++){
    if(check(cur,i)){
      ans[++tot]=i;
      vis_line[i]=1;
      vis_dia1[cur+i-1]=1;
      vis_dia2[cur+(n-i+1)-1]=1;
      dfs(cur+1);
      vis_line[i]=0;
      vis_dia1[cur+i-1]=0;
      vis_dia2[cur+(n-i+1)-1]=0;
      tot--;
    }
  }
  return ;
}
ll main(){
  freopen("1219.in","r",stdin);
  freopen("1219.out","w",stdout);
  cin>>n;
  dfs(1);
  cout<<cnt<<endl;
  return 0;
}
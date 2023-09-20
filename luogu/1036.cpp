#include<bits/stdc++.h>
using namespace std;
const ll N=25;
ll s[N],n,k,ans;
bool judge_prime(ll x){
  for(ll i=2;i*i<=x;i++)if(x%i==0)return false;
  return true;
}
void dfs(ll cur,ll cnt,ll sum){
  if(cur==n+1){
    if(cnt==k){
      if(judge_prime(sum))ans++;
    }
    return ;
  }  
  dfs(cur+1,cnt+1,sum+s[cur]);
  dfs(cur+1,cnt,sum);
}
ll main(){
  freopen("1036.in","r",stdin);
  freopen("1036.out","w",stdout);
  cin>>n>>k;
  for(ll i=1;i<=n;i++)cin>>s[i];
  dfs(1,0,0);
  cout<<ans<<endl;
  return 0;
}
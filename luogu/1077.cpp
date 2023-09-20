#include<bits/stdc++.h>
using namespace std;
const ll N=105;
const ll mod=1e6+7;
ll a[N],n,m;
ll f[N][N],ans;
ll dfs(ll kdl,ll cnt){
  if(cnt==m){
    return 1;
  }
  if(cnt>m)return 0;
  if(kdl==n+1)return 0;
  if(f[kdl][cnt])return f[kdl][cnt];
  ll aa=0;
  for(ll i=0;i<=a[kdl];i++)aa=(aa+dfs(kdl+1,cnt+i))%mod;
  return f[kdl][cnt]=aa;
}
ll main(){
  freopen("1077.in","r",stdin);
  freopen("1077.out","w",stdout);
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
    cin>>a[i];
  cout<<dfs(1,0)<<endl;
  return 0;
}
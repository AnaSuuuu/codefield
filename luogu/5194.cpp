#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
ll w[N],ans;
ll n,c,sum[N];
void dfs(int now,ll num){
  ans=max(ans,num);
  if(num+sum[now]<=ans)return ;
  if(num+sum[now]<=c){
    ans=max(num+sum[now],ans);
    return ;
  }
  if(now==0)return ;
  dfs(now-1,num);
  if(num+w[now]<=c)dfs(now-1,num+w[now]);
}
int main(){
	freopen("5194.in","r",stdin);
	freopen("5194.out","w",stdout);	
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]),sum[i]=sum[i-1]+w[i];
	dfs(n,0);
  cout<<ans<<endl;
	return 0;
}


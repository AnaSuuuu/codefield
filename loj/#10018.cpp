#include<bits/stdc++.h>
using namespace std;
ll n,k;
ll ans;
void dfs(ll _last,ll num,ll _left){
	if((num==k)&&(_left==0)){
		ans++;
		return ;
	}
	if(num>k)return ;
	for(ll i=_last;i<=_left/2;i++){
		//if(_left-i<i)continue;
		dfs(i,num+1,_left-i);
	}
	if((num==k-1)&&(_left>=_last))ans++;
}
ll main(){
	freopen("#10018.in","r",stdin);
	freopen("#10018.out","w",stdout);
	scanf("%d%d",&n,&k);
	dfs(1,0,n);
	prllf("%d\n",ans);
	return 0;
}


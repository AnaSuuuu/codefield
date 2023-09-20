#include<cstdio>
#include<cstring>
#include<iostream>
#define ll unsigned long long
using namespace std;
int mid,ok,ans;
int s[100];
ll lowbit(ll x){
    return x & (-x);
}
void dfs(int tmp,ll kdl){
	if(tmp>mid)return ;
	if(kdl==0){
		ok=1;
		return ;
	}
	if(ok)return ;
	dfs(tmp+1,kdl-lowbit(kdl));
	dfs(tmp+1,kdl+lowbit(kdl));
	return ;
}/**/
int kdl;
void work(ll x){
	kdl=0;
	memset(s,0,sizeof(s));
	while(x){
		s[++kdl]=x%2;
		x/=2;
	}
	//for(int i=kdl;i>=1;i--)printf("%d",s[i]);
}
int main(){
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	for(ll n=1;n<=100;n++){
	work(n);
	int l=1,r=63;
	while(l<=r){
		mid=(l+r)/2;
		ok=0;
		dfs(0,n);
		if(ok){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	}
	puts("");
	for(ll n=1;n<=100;n++){
		ans=0;
		work(n);
	for(int i=1;i<=kdl;i++){
		if(s[i]==0)continue;
		if(s[i]==1&&s[i+1]==0)ans++;
		else {
			while(s[i+1]==1)i++;
			if(s[i+2]==0)ans+=2;
			else s[i+1]=1,ans++;
		}
	}
	printf("%d\n",ans);
	}
	
	return 0;
}


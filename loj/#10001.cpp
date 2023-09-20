#include<bits/stdc++.h>
using namespace std;
const ll N=5005;
const ll M=3e4+5;
struct Node{
	ll b,e,t;
}s[N];
bool cmp(Node x,Node y){
	if(x.e==y.e)return x.b<y.b;
	return x.e<y.e;
}
ll vis[M];
ll main(){
	freopen("#10001.in","r",stdin);
	freopen("#10001.out","w",stdout);
	ll n,h,ans=0;
	scanf("%d",&n);
	scanf("%d",&h);
	for(ll i=1;i<=h;i++)scanf("%d%d%d",&s[i].b,&s[i].e,&s[i].t);
	sort(s+1,s+1+h,cmp);
	for(ll i=1;i<=h;i++){
		for(ll j=s[i].b;j<=s[i].e;j++){
			if(vis[j])s[i].t--;
			if(s[i].t<=0)break;
		}
		if(s[i].t<=0)continue;
		for(ll j=s[i].e;j>=s[i].b;j--){
			if(!vis[j]){
				vis[j]=1;s[i].t--;ans++;
			}
			if(s[i].t<=0)break;
		}
	}
	prllf("%d\n",ans);
	return 0;
}


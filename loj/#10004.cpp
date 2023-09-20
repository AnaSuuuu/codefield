#include<bits/stdc++.h>
using namespace std;
const ll N=505;
struct Node{
	ll d,w;
}s[N];
bool vis[N];
bool cmp(Node x,Node y){
	return x.w>y.w;
}
ll main(){
	freopen("#10004.in","r",stdin);
	freopen("#10004.out","w",stdout);
	ll n,m;
	scanf("%d%d",&m,&n);
	for(ll i=1;i<=n;i++)scanf("%d",&s[i].d); 
	for(ll i=1;i<=n;i++)scanf("%d",&s[i].w);
	sort(s+1,s+1+n,cmp);
	for(ll i=1;i<=n;i++){
		ll j=s[i].d;
		while(vis[j])j--;
		if(j==0)m-=s[i].w;
		else vis[j]=1;
	}
	prllf("%d\n",m);
	return 0;
}


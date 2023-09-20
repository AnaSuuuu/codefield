#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+5;
const ll M=7e5+5;
struct Node{
	ll d,w;
}s[N];
bool vis[M];
bool cmp(Node x,Node y){
	return x.w>y.w; 
}
inline void in(ll &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	} 
	
}
ll main(){
	freopen("#10008.in","r",stdin);
	freopen("#10008.out","w",stdout);
	ll n,ans=0;
	in(n);
	ll maxn=0;	
	for(ll i=1;i<=n;i++)in(s[i].d),in(s[i].w);
	sort(s+1,s+1+n,cmp);
	for(ll i=1;i<=n;i++){
		ll ok=1;
		if(maxn>=s[i].d)continue;;
		for(ll j=s[i].d;j>=1;j--){
			if(!vis[j]){
				ok=0;
				vis[j]=1;
				ans+=s[i].w;
				break;
			}
		}
		if(ok)maxn=max(maxn,s[i].d);
	}
	prllf("%d\n",ans);
	return 0;
}


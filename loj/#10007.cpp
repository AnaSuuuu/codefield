#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+5;
struct Node{
	ll a,b;
}s[N];
bool cmp(Node x,Node y){
	return x.b<y.b;
}
ll main(){
	freopen("#10007.in","r",stdin);
	freopen("#10007.out","w",stdout);
	ll n;
	scanf("%d",&n);
	for(ll i=1;i<=n;i++)scanf("%d%d",&s[i].a,&s[i].b);
	sort(s+1,s+1+n,cmp);
	ll _tail=0,ans=0;
	for(ll i=1;i<=n;i++){
		if(s[i].a>=_tail){
			ans++;
			_tail=s[i].b;
		}
	}
	prllf("%d\n",ans);
	return 0;
}


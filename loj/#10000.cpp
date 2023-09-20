#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
struct Node{
	ll s,f;
}a[N];
bool cmp(Node x,Node y){
	return (x.f==y.f)?(x.s<y.s):(x.f<y.f);
}
ll main(){
	freopen("#10000.in","r",stdin);
	freopen("#10000.out","w",stdout);
	ll n;
	scanf("%d",&n);
	for(ll i=1;i<=n;i++)scanf("%d%d",&a[i].s,&a[i].f);
	sort(a+1,a+1+n,cmp);
	ll ans=1,tmp=a[1].f;
	/*for(ll i=1;i<=n;i++){
		cout<<a[i].s<<' '<<a[i].f<<endl;
	}*/
	for(ll i=2;i<=n;i++)
		if(a[i].s>=tmp)ans++,tmp=a[i].f;
	prllf("%d\n",ans);
	return 0;
}


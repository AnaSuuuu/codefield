#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll a[N],b[N];
ll main(){
	freopen("#10010.in","r",stdin);
	freopen("#10010.out","w",stdout);
	ll n,sum=0,ave;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i];
	ave=sum/n;
	for(ll i=1;i<=n;i++)b[i]=b[i-1]+(ave-a[i]);
	sort(b+1,b+1+n);
	ll kdl=b[(n>>1)+1],ans=0;
	for(ll i=1;i<=n;i++)ans+=abs(kdl-b[i]);
	prllf("%lld\n",ans);
	return 0;
}


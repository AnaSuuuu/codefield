#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a[N],tot,ans=1;
ll main(){
	freopen("#10006.in","r",stdin);
	freopen("#10006.out","w",stdout);
	ll n,m;
	scanf("%d%d",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%d",&a[i]),tot+=a[i];
		if(tot>m)tot=a[i],ans++;
	}
	prllf("%d\n",ans);
	return 0;
}


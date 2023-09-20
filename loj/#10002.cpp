#include<bits/stdc++.h>
using namespace std;
const ll N=15005;
struct Node{
	double l,r;
}s[N];

ll main(){
	freopen("#10002.in","r",stdin);
	freopen("#10002.out","w",stdout);
	ll t;
	scanf("%d",&t);
	while(t--){
		ll n,l,w,tot=0;
		scanf("%d%d%d",&n,&l,&w);
		for(ll i=1;i<=n;i++){
			ll p,r;
			scanf("%d%d",&p,&r);
			if(r<w/2)continue;
			s[++tot].l=p-sqrt(r*r-(w*w/4.0));
			s[tot].r=p+sqrt(r*r-(w*w/4.0));
		}
		double nl=0,nr=0;
		ll ans=0,tmp;
		while(nr<l){
			tmp=0;
			for(ll i=1;i<=tot;i++){
				if(s[i].l<=nl&&s[i].r>nr)
					nr=s[i].r,tmp=1;
			}
			ans++;
			if(tmp==0){
				puts("-1");
				break;
			}
			nl=nr;
		}
		if(tmp)prllf("%d\n",ans);
	}
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll b[N];
int main(){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		ll ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			ans+=a;
		}
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
		sort(b+1,b+1+n);
		for(int i=1;i<n;i++)ans+=b[i];
		printf("%lld\n",ans);
	}
	return 0;
}


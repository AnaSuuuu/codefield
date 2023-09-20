#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int main(){
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
	int t,num=0;
	scanf("%d",&t);
	while(t--){
		num++;
		ll n,m;
		scanf("%lld%lld",&n,&m);
		n-=2;m-=2;
		printf("Case %d: %lld\n",num,((n*n*(n+1)*(n+5)/12%mod+n*(n+1)/2)%mod*((m*m*(m+1)*(m+5)/12%mod+m*(m+1)/2)%mod))/4%mod);
	}
	return 0;
}


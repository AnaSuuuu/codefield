#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ll x,y;
		scanf("%lld",&x);
		y=1000000000000ll/x;
		double x0=x;
		//printf("%lf ",1.0/x0);
		if(x*y==1000000000000ll)printf("No");
		else printf("Yes");
		if(t>=1)puts("");
	}
	return 0;
}


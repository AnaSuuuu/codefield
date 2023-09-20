#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+6;
ll kdl;
char a[N];
int main(){
	freopen("C - And and Pair.in","r",stdin);
	freopen("C - And and Pair.out","w",stdout);
	ll t;
	scanf("%d",&t);
	while(t--){
		
		scanf("%s",a+1);
		int len=strlen(a+1);
		ll ans=1;kdl=1;
		for(int i=len;i>=1;i--){
			if(a[i]=='0')kdl=kdl*2ll,kdl%=mod;
			else if(a[i]=='1'){
				ans=(ans+kdl)%mod;
				kdl*=3ll;kdl%=mod;
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
}


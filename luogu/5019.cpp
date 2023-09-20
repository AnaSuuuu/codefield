#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll h[N];
int main(){
	freopen("5019.in","r",stdin);
	freopen("5019.out","w",stdout);
	int n;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	for(int i=2;i<=n;i++)ans+=(h[i]>h[i-1])?(h[i]-h[i-1]):0;
	cout<<ans+h[1]<<endl;
	return 0;
}


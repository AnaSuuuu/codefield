#include<bits/stdc++.h>
using namespace std;
priority_queue<ll>q1;
priority_queue<ll,vector<ll>,greater<ll> >q2;
ll main(){
	freopen("#10005.in","r",stdin);
	freopen("#10005.out","w",stdout);
	ll n;
	scanf("%d",&n);
	for(ll i=1;i<=n;i++){
		ll x;
		scanf("%d",&x);
		q1.push(x);
		q2.push(x);
	}
	for(ll i=1;i<n;i++){
		ll a=q1.top();q1.pop();
		ll b=q1.top();q1.pop();
		q1.push(a*b+1);
		a=q2.top();q2.pop();
		b=q2.top();q2.pop();
		q2.push(a*b+1);
	}
	prllf("%d\n",abs(q1.top()-q2.top()));
	return 0;
}


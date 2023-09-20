#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
struct Node{
	ll a,b,m,id;
}s[N],q[N];
ll m;
bool cmp(Node x,Node y){
	return x.m<y.m;
}
ll main(){
	freopen("#10003.in","r",stdin);
	freopen("#10003.out","w",stdout);
	ll n;
	scanf("%d",&n);
	for(ll i=1;i<=n;i++)scanf("%d",&s[i].a),s[i].id=i;
	for(ll i=1;i<=n;i++)scanf("%d",&s[i].b);
	for(ll i=1;i<=n;i++)s[i].m=min(s[i].a,s[i].b);
	sort(s+1,s+1+n,cmp);
	ll _head=0,_tail=n+1;
	for(ll i=1;i<=n;i++){
		if(s[i].m==s[i].a){
			q[++_head].a=s[i].a;
			q[_head].b=s[i].b;
			q[_head].id=s[i].id;
		}
		else {
			q[--_tail].a=s[i].a;
			q[_tail].b=s[i].b;
			q[_tail].id=s[i].id;
		}
	}
	//for(ll i=1;i<=n;i++)cout<<q[i].a<<' '<<q[i].b<<endl;
	ll ans=0,kdl=0;
	for(ll i=1;i<=n;i++){
		ans+=q[i].a;
		kdl=max(kdl,ans)+q[i].b;
	}
	prllf("%d\n",kdl);
	cout<<q[1].id;
	for(ll i=2;i<=n;i++)prllf(" %d",q[i].id);
	return 0;
}


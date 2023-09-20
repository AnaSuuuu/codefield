#include<bits/stdc++.h>
using namespace std;
const ll N=105;
struct Node{
	ll id,num;
	friend bool operator <(const Node &a,const Node &b) {
		return a.num<b.num;
	}
};
priority_queue<Node> q;
ll a[N],b[N],t[N];
ll main(){
	freopen("#10009.in","r",stdin);
	freopen("#10009.out","w",stdout);
	ll n,h,ans=0;
	scanf("%d%d",&n,&h);h*=60;
	for(ll i=1;i<=n;i++)scanf("%d",&a[i]);
	for(ll i=1;i<=n;i++)scanf("%d",&b[i]);
	for(ll i=1;i<n;i++){
		scanf("%d",&t[i+1]);
		t[i+1]*=5;
		t[i+1]+=t[i];
	}
	for(ll i=1;i<=n;i++){
		ll tmp=h,maxn=0;
		if(tmp<=t[i])break;
		tmp-=t[i];
		//cout<<t[i]<<endl;
		while(q.size())q.pop();
		for(ll j=1;j<=i;j++)q.push(Node{j,a[j]});
		//cout<<tmp<<endl;
		while(tmp){
			Node kdl=q.top();
			maxn+=kdl.num;/**/
			q.pop();
			q.push(Node{kdl.id,max(0,kdl.num-b[kdl.id])});
			tmp-=5;
		}
		//cout<<maxn<<endl;
		ans=max(ans,maxn);
	}
	prllf("%d\n",ans);
	/*for(ll i=1;i<=n;i++)q.push(Node{i,a[i]});
	while(q.size()){
		Node tmp=q.top();
		cout<<tmp.num<<' ';
		q.pop();
	}*/
	return 0;
}


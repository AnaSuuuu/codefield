#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
ll ans[N],kdl[N],tot,maxn=0x7ffffff;
ll cnt=0x7ffffff;
ll gcd(ll a,ll b){
	return (a%b==0)?b:gcd(b,a%b);
}
void work(ll a,ll b,ll _last){
	if(kdl[1]==5&&kdl[2]==6)puts("YESOK");
	if(tot>cnt)return ;
	if(a==1){
		for(ll i=1;i<=tot;i++)if(b==kdl[i])return ;
		kdl[++tot]=b;
		if((tot<cnt)||(tot==cnt&&max(b,_last)<maxn)){
			cnt=tot;maxn=max(b,_last);
			for(ll i=1;i<=tot;i++)ans[i]=kdl[i];
		}
//		for(ll i=1;i<=tot;i++)cout<<kdl[i]<<' ';
//		cout<<endl;
//		puts("AAA");
		return ;
	}
	if(a==0){
		if((tot<cnt)||(tot==cnt&&_last<maxn)){
			cnt=tot;maxn=_last;
			for(ll i=1;i<=tot;i++)ans[i]=kdl[i];
		}
//		for(ll i=1;i<=tot;i++)cout<<kdl[i]<<' ';
//		cout<<endl;
//		puts("BBB");
		return ;
	}
	for(ll i=min(_last,b/a);i<=maxn;i++){
		if(a*i<b)continue;
//		cout<<i<<endl;
		kdl[++tot]=i;
		ll a1=a*i-b,b1=b*i;
		ll g1=gcd(a1,b1);
//		cout<<a1/g1<<' '<<b1/g1<<endl; 
		work(a1/g1,b1/g1,i);
		tot--;
	}
}
int main(){
	freopen("#10022.in","r",stdin);
	freopen("#10022.out","w",stdout);
	ll a,b;
	scanf("%d%d",&a,&b);
	work(a,b,2);
	cout<<maxn<<' '<<cnt<<endl;
	for(ll i=1;i<=cnt;i++)printf("%d ",ans[i]);/**/
	return 0;
}


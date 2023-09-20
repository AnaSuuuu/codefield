#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int d,t;
}s[N];
bool cmp(Node x,Node y){
	return x.d<y.d;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,num=0;
	scanf("%d",&t);
	while(t--){
		num++;
		int n,m;int ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&s[i].d);
		for(int i=1;i<=n;i++)scanf("%d",&s[i].t);
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(m>=s[i].t){
				m-=s[i].t;
				ans++;
			}
			else break;
		}
		printf("Case %d: %d\n",num,ans);
	}
	return 0;
}


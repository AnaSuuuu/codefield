#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int ans[N],maxn; 
int main(){
	freopen("1113.in","r",stdin);
	freopen("1113.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int id,len;
		scanf("%d%d",&id,&len);
		int x,tmp=0;
		scanf("%d",&x);
		while(x!=0){
			tmp=max(tmp,ans[x]);
			scanf("%d",&x);
		}
		ans[i]=tmp+len;
		maxn=max(maxn,ans[i]);
	}
	printf("%d\n",maxn);
	return 0;
}


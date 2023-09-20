#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],n,b[N];
int cal(int x){
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(b[mid]<=x){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
bool judge(int k){
	for(int i=1;i<=k;i++){
		//for(int j=1;j<=n;j++)cout<<a[j]<<' ';
		//cout<<endl;
		int x=cal(k-i+1);
		if(b[x]>k-i+1)return false;
		b[x]=105;
		b[1]+=(k-i+1);
		sort(b+1,b+1+n);
	}
	return true;
}
int main(){
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		//cout<<judge(2)<<endl;
		int l=0,r=n,ans;
		//cout<<judge(1)<<' '<<judge(2)<<' '<<judge(3)<<endl;
		while(l<=r){
			for(int i=1;i<=n;i++)b[i]=a[i];
			int mid=(l+r)>>1;
			if(judge(mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);/**/
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N][N],b[N][N];
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,kdl=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]),b[i][j]=a[i][j];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]!=b[n-i+1][n-j+1])kdl++;
			}
		}
		kdl/=2;
		//cout<<kdl<<endl;
		if(n&1){
			if(kdl>k)puts("NO");
			else puts("YES");
		}
		else if(((kdl&1)^(k&1))||(kdl>k))puts("NO");
					else puts("YES");
	}
	return 0;
}


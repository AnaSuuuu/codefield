#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[55][N],cnt[55];
int c[55*N],b[55][N];
bool M[55][N*50];
int main(){
	freopen("L2-005.in","r",stdin);
	freopen("L2-005.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		for(int j=1;j<=a[i][0];j++)scanf("%d",&a[i][j]),c[++c[0]]=a[i][j];
	}
	sort(c+1,c+1+c[0]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i][0];j++)
			a[i][j]=lower_bound(c+1,c+1+c[0],a[i][j])-c;
	//cout<<a[1][0]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i][0];j++){
			if(!M[i][a[i][j]])b[i][++b[i][0]]=a[i][j];
			M[i][a[i][j]]=1;
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int u,v;
		double x=0;
		scanf("%d%d",&u,&v);
		for(int j=1;j<=b[u][0];j++){
			if(M[v][b[u][j]])x++;
		}		
		//cout<<b[u][0]<<endl;
		printf("%.2lf%\n",(double)x/(b[u][0]+b[v][0]-x)*100);
	}
	return 0;
}


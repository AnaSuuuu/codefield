#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int lower[N],cal[N];
int num[N];//num[i]表示i在lower数组中要找第num[i]个 ,即lower[num[i]]>=i 
int vis[N];
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int n;
	int tmp=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		int kdl=n,id;
		for(int j=1;j<=n;j++){
			if((vis[j]==0)&&((a[i]+b[j])%n<kdl)){
				kdl=(a[i]+b[j])%n;
				id=j;
			}
		}
		vis[id]=1;
		printf("%d ",(a[i]+b[id])%n);
	}
	return 0;
}


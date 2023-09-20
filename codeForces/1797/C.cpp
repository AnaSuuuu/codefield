#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int x=1,y=1,k1,k2,k3;
		int n,m;
		scanf("%d%d",&n,&m);
		printf("? 1 1\n");
		fflush(stdout);
		scanf("%d",&k1);
		if(k1>=n){
			printf("? 1 %d\n",k1+1);
			fflush(stdout);
			scanf("%d",&k2);
			printf("! %d %d\n",k2+1,k1+1);
			fflush(stdout);
		}
		else if(k1>=m){
			printf("? %d 1\n",k1+1);
			fflush(stdout);
			scanf("%d",&k2);
			printf("! %d %d\n",k1+1,k2+1);
			fflush(stdout);
		}
			else {
				printf("? 1 %d\n",k1+1);
				fflush(stdout);
				scanf("%d",&k2);
				printf("? %d 1\n",k1+1);
				fflush(stdout);
				scanf("%d",&k3);
				if(k3<k1)printf("! %d %d\n",k1+1,k3+1);
				else printf("! %d %d\n",k2+1,k1+1);
				fflush(stdout);
			}
	}
	fflush(stdout);
	return 0;
}


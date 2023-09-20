#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,x0,y0,x1,y1;
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		if(((x0==1)&&(y0==1))||((x0==n)&&(y0==m))||((x0==n)&&(y0==1))||((x0==1)&&(y0==m))){
			puts("2");
			continue;
		}
		if(((x1==1)&&(y1==1))||((x1==n)&&(y1==m))||((x1==n)&&(y1==1))||((x1==1)&&(y1==m))){
			puts("2");
			continue;
		}
		if(x0==1||y0==1||x0==n||y0==m){
			puts("3");
			continue;
		}
		if(x1==1||y1==1||x1==n||y1==m){
			puts("3");
			continue;
		}
		puts("4");
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=15;
int r[N],l[N];
bool map_r[N],map_l[N];
int main(){
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,kdl=0;
		scanf("%d%d",&n,&m);
		memset(r,0,sizeof(r));
		memset(l,0,sizeof(l));
		memset(map_r,0,sizeof(map_r));
		memset(map_l,0,sizeof(map_l));
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			r[x]++;l[y]++;
			if(r[x]>=2){
				if(map_r[x]==0)kdl++;
				map_r[x]=1;
			}
			if(l[x]>=2){
				if(map_l[x]==0)kdl++;
				map_l[x]=1;
			}
		}
		if((m>n)||(kdl>=2)){
			puts("NO");
			continue;
		}
		if(m==n&&kdl==0){
			puts("NO");
			continue;
		}
		puts("YES");
		continue;
	}
	return 0;
}


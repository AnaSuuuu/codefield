#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int nxt[N],cnt[N];
int is_del[N],vis[N];
void out(int x){
	if(x<0){
		printf("%d\n",x);
		return ;
	}
	if(x<10000)putchar('0');
	if(x<1000)putchar('0');
	if(x<100)putchar('0');
	if(x<10)putchar('0');
	printf("%d",x);
}
int main(){
	freopen("L2-002.in","r",stdin);
	freopen("L2-002.out","w",stdout);
	int head,n;
	scanf("%d%d",&head,&n);
	for(int i=1;i<=n;i++){
		int u,w,v;
		scanf("%d%d%d",&u,&w,&v);
		cnt[u]=w;
		nxt[u]=v;
	}
	int ok=1,tt=-2;
	for(int i=1,j=head;i<=n+1;i++,j=nxt[j]){
		if((j==-1)||(!vis[abs(cnt[j])])){
			if(ok){
				vis[abs(cnt[j])]=1;
				out(j);
				printf(" %d ",cnt[j]);
				is_del[j]=1;
				ok=0;
			}
			else{
				out(j);
				if(j!=-1){
					puts("");
					out(j);
					printf(" %d ",cnt[j]);
					vis[abs(cnt[j])]=1;
					is_del[j]=1;
				}
			}
		}
		else tt=j;
	}
	ok=1;
	if(tt==-2)return 0; 
	for(int i=1,j=head;i<=n;i++,j=nxt[j]){
		if(!is_del[j]){
			if(ok){
				out(j);
				printf(" %d ",cnt[j]);
				ok=0;
			}
			else{
				out(j);
				puts("");
				out(j);
				printf(" %d ",cnt[j]);
			}
		}
	}
	cout<<-1;
	return 0;
}


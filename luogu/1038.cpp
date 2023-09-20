#include<bits/stdc++.h>
using namespace std;
const int N=105;
int w[N][N],e[N][N];
int u[N],c[N],ok=1;
int s[N],vis[N],aha[N];
queue<int> q; 
int main(){
	freopen("1038.in","r",stdin);
	freopen("1038.out","w",stdout);
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&u[i]);
		if(c[i]>0)q.push(i),vis[i]=1;
		else c[i]-=u[i];
	}
	for(int i=1;i<=p;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		scanf("%d",&w[u][v]);
	}
	while(q.size()){
		int kdl=0;
		while(q.size()){
			int tmp=q.front();
			q.pop();
			//cout<<tmp<<endl;
			for(int i=1;i<=n;i++){
				if(((w[tmp][i]!=0)&&(vis[i]==0))){
					c[i]+=w[tmp][i]*c[tmp];
					aha[tmp]=1;
					s[++kdl]=i;
				}
			}
		}
		for(int i=1;i<=kdl;i++){
			if((c[s[i]]>0)&&(vis[s[i]]==0))q.push(s[i]),vis[s[i]]=1;
		}
	}
	for(int i=1;i<=n;i++)
		if((aha[i]==0)&&(c[i]>0))printf("%d %d\n",i,c[i]),ok=0;
	if(ok)puts("NULL");
	return 0;
}


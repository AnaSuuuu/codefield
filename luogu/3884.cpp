#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct Edge{
	int _to,_next;
}e[N<<1];
int tot,head[N],dep[N],fa[N],sum[N];
int son[N],cnt[N],top[N],dis[N];
void add_edge(int u,int v){
	e[++tot]._to=v;
	e[tot]._next=head[u];
	head[u]=tot;
}
void dfs1(int u){
	sum[u]=1;
	int maxn=-1;
	for(int i=head[u];i;i=e[i]._next){
		int v=e[i]._to;
		if(!dep[v]){
			dep[v]=dep[u]+1;
			cnt[dep[v]]++;
			fa[v]=u;
			dfs1(v);
			sum[u]+=sum[v];
			if(sum[v]>maxn){
				maxn=sum[v];
				son[u]=v;
			}
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(son[u])dfs2(son[u],topf);
	for(int i=head[u];i;i=e[i]._next)
		if(!top[e[i]._to])dfs2(e[i]._to,e[i]._to);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])return y;
	return x;
}
int main(){
	freopen("3884.in","r",stdin);
	freopen("3884.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	int x,y;
	scanf("%d%d",&x,&y);
	dep[1]=1;cnt[1]=1;
	dfs1(1);
	dfs2(1,1);
	int D=0,W=0;
	for(int i=1;i<=n;i++)D=max(D,dep[i]),W=max(W,cnt[dep[i]]);
	printf("%d\n%d\n",D,W);
	printf("%d",(dep[x]-dep[lca(x,y)])*2+dep[y]-dep[lca(x,y)]);
	return 0;
}


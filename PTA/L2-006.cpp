#include<bits/stdc++.h>
using namespace std;
const int N=35;
const int M=1e5+5;
int a[N],b[N];
int dep[M];
int cnt[N][N],D=1;
int tot,head[M];
struct Edge{
	int _to,_next;
}e[N];
void add_edge(int u,int v){
	e[++tot]._next=head[u];
	e[tot]._to=v;
	head[u]=tot;
}
void dfs0(int root,int l,int r,int nl,int nr){
	int i;
	//cout<<l<<' '<<r<<' '<<nl<<' '<<nr<<endl;
	if(l>r)return ;
	if(l==r){
		add_edge(root,a[l]);
		return ;
	}
	for(i=l;i<=r;i++)if(a[i]==b[nr])break;
	add_edge(root,a[i]);
	dfs0(a[i],l,i-1,nl,i-l-1+nl);
	dfs0(a[i],i+1,r,i-l+nl,nr-1);
}
void dfs1(int u){
	for(int i=head[u];i;i=e[i]._next){
		int v=e[i]._to;
		dep[v]=dep[u]+1;
		D=max(D,dep[v]);
		cnt[dep[v]][++cnt[dep[v]][0]]=v;
		dfs1(v);
	}
}
int main(){
	freopen("L2-006.in","r",stdin);
	freopen("L2-006.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs0(0,1,n,1,n);
	dep[b[n]]=1;
	cnt[1][++cnt[1][0]]=b[n];
	dfs1(b[n]);
	for(int i=1;i<D;i++){
		for(int j=cnt[i][0];j>=1;j--)cout<<cnt[i][j]<<' ';
	}
	for(int i=cnt[D][0];i>=2;i--)cout<<cnt[D][i]<<' ';
	cout<<cnt[D][1];
	return 0;
}


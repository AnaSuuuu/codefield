#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,vis[N],ans;
int col[N],sccCnt;
int cc[N],vv[N],sum[N];
vector<int>e[N],e1[N],E[N],q;
int a[N],u0[N],v0[N];
void dfs1(int u){
	vis[u]=1;
	for (int _to:e[u])if(!vis[_to])dfs1(_to);
	q.push_back(u);
}
void dfs2(int u){
	col[u]=sccCnt;
	for(int _to:e1[u])if(!col[_to])dfs2(_to);
}
void dfs3(int u){
	sum[u]=cc[u],vv[u]=1;
	for(int _to:E[u]){
    //cout<<u<<' '<<_to<<endl;
		if(!vv[_to])  dfs3(_to);
		sum[u]=max(sum[u],cc[u]+sum[_to]);
	}
}
int main(){
	freopen("3387.in","r",stdin);
	freopen("3387.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u0[i],&v0[i]);
		e[u0[i]].push_back(v0[i]),e1[v0[i]].push_back(u0[i]);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs1(i);	
	for(int i=n-1;i>=0;i--){
		if(!col[q[i]]){
			sccCnt++;
			dfs2(q[i]);
      //cout<<q[i]<<endl;
		}
	}/**/
  //cout<<sccCnt<<endl;
	for(int i=1;i<=n;i++)
		cc[col[i]]+=a[i];
	for(int i=1;i<=m;i++){
		if(col[u0[i]]!=col[v0[i]])E[col[u0[i]]].push_back(col[v0[i]]);
	}
  /*for(int i=1;i<=sccCnt;i++)cout<<cc[i]<<' ';
  cout<<endl;*/
	for(int i=1;i<=sccCnt;i++)if(!vv[i])dfs3(i);
	for(int i=1;i<=sccCnt;i++)ans=max(ans,sum[i]); 
	cout<<ans<<endl;
  //for(int i=1;i<=sccCnt;i++)cout<<sum[i]<<' ';
  //  cout<<endl;
	return 0;
}


#include<cstdio>
using namespace std;
const ll N=105;
char s[N][N];
const ll zh[][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}};
bool vis[N][N];
ll n,m,ans;
void dfs(ll x,ll y){
	vis[x][y]=1;
	for(ll i=0;i<8;i++){
		ll dx=x+zh[i][0],dy=y+zh[i][1];
		if(dx<=0||dx>n||dy<=0||dy>m)continue;
		if(vis[dx][dy])continue;
		if(s[dx][dy]=='W')dfs(dx,dy);
		else vis[dx][dy]=1;
	}
}
ll main(){
	freopen("1596.in","r",stdin);
	freopen("1596.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(vis[i][j]||s[i][j]=='.'){
				vis[i][j]=1;
				continue;
			}
			dfs(i,j);
			//prllf("%d %d\n",i,j);
			ans++;
		} 
	}
	prllf("%d\n",ans);
	return 0;
}


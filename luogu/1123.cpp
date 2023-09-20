#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const ll N=10;
ll s[N][N],vis[N][N];
ll n,m,ans,num[N][N];
const ll zh[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool judge(ll x,ll y){
	for(ll i=0;i<8;i++){
		ll dx=x+zh[i][0],dy=y+zh[i][1];
		if(dx<1||dx>n||dy<1||dy>m)continue;
		if(vis[dx][dy])return false;
	}
	return true;
}
void dfs(ll x,ll y,ll kdl){
	if(kdl>ans)ans=kdl;
  if(y==m+1)y=1,x++;
  if(x==n+1)return ;
	dfs(x,y+1,kdl);
  if(judge(x,y)){
    vis[x][y]=1;
    dfs(x,y+1,kdl+s[x][y]);
    vis[x][y]=0;
  }
}
ll main(){
	freopen("1123.in","r",stdin);
	freopen("1123.out","w",stdout);
	ll t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
    for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++)scanf("%d",&s[i][j]);
		dfs(1,1,0);
		prllf("%d\n",ans);
	}
	return 0;
}


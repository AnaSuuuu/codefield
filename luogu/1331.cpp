#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const ll N=1e3+5;
char s[N][N];
bool vis[N][N];
ll r,c,ans;
bool judge(ll x,ll y,ll X,ll Y){
	for(ll i=x;i<=X;i++){
		for(ll j=y;j<=Y;j++)if(s[i][j]!='#')return false;
	}
	if(x-1>0)
		for(ll j=y;j<=Y;j++)if(s[x-1][j]!='.')return false;
	if(X+1<=r)
		for(ll j=y;j<=Y;j++)if(s[X+1][j]!='.')return false;
	if(y-1>0)
		for(ll i=x;i<=X;i++)if(s[i][y-1]!='.')return false;
	if(Y+1<=c)
		for(ll i=x;i<=X;i++)if(s[i][Y+1]!='.')return false;
	return true;
} 
void work(ll x,ll y,ll X,ll Y){
	for(ll i=x;i<=X;i++)
		for(ll j=y;j<=Y;j++)vis[i][j]=1;
}
ll main(){
	freopen("1331.in","r",stdin);
	freopen("1331.out","w",stdout);
	scanf("%d%d",&r,&c);
	for(ll i=1;i<=r;i++)scanf("%s",s[i]+1);
	for(ll i=1;i<=r;i++){
		for(ll j=1;j<=c;j++){
			if(s[i][j]=='.'||vis[i][j])continue;
			ll x,y;
			for(x=i;(x<=r)&&(s[x][j]=='#');x++);x--;
			for(y=j;(y<=c)&&(s[x][y]=='#');y++);y--;
			//prllf("%d %d %d %d\n",i,j,x,y);
			if(judge(i,j,x,y)){
				ans++;
				work(i,j,x,y);
			}
			else {
				puts("Bad placement.");
				return 0;
			}
		}
	}
	prllf("There are %d ships.\n",ans);
	//else 
	//puts("Bad placement.");
	return 0;
}


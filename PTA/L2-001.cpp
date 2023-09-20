#include<bits/stdc++.h>
using namespace std;
const int N=505;
int w[N],vis[N];
int head[N],tot;
int rep[N],te;
int dis[N],cnt[N];
int s,d,ans,maxn=-1,minn=0x3f3f3f3f;
struct Edge{
  int _to,_next,_dis;
}e[N*N];
void add_edge(int u,int v,int d){
  e[++tot]._to=v;
  e[tot]._next=head[u];
  e[tot]._dis=d;
  head[u]=tot;
}
void dfs(int u,int kdl,int dist,int num){
	if(u==d){
		if(dist==minn){
			ans++;
			if(kdl>maxn){
				maxn=kdl;
				te=num;
				for(int i=1;i<=num;i++)rep[i]=cnt[i];
			}
		}
		else {
			ans=1;
			maxn=kdl;
			minn=dist;
			te=num;
			for(int i=1;i<=num;i++)rep[i]=cnt[i];
		}
		return ;
	}
	if(dist>minn)return ;
	for(int i=head[u];i;i=e[i]._next){
		int v=e[i]._to;
		if(dis[v]>=dis[u]+e[i]._dis){
			dis[v]=dis[u]+e[i]._dis;
			cnt[num+1]=v;
			dfs(v,kdl+w[v],dist+e[i]._dis,num+1);
		}
	}
}
int main(){
  freopen("L2-001.in","r",stdin);
  freopen("L2-001.out","w",stdout);
  int n,m;
  scanf("%d%d%d%d",&n,&m,&s,&d);
  for(int i=0;i<n;i++)scanf("%d",&w[i]);
  for(int i=1;i<=m;i++){
  	int u,v,d;
  	scanf("%d%d%d",&u,&v,&d);
  	add_edge(u,v,d);
  	add_edge(v,u,d);
  } 
  memset(dis,0x3f,sizeof(dis));
  dis[s]=0;
  cnt[1]=s;
	dfs(s,w[s],0,1);
  printf("%d %d\n",ans,maxn);
  for(int i=1;i<te;i++)printf("%d ",rep[i]);
  printf("%d",rep[te]);
	return 0;
}

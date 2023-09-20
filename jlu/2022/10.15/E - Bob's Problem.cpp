#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int fa[N];
bool _ok[N];
struct Edge{
	int u,v,w;
}e[N];
inline int f(int x){
	if(fa[x]==x)return x;
	return fa[x]=f(fa[x]);
}
bool cmp(Edge a,Edge b){
	return a.w>b.w;
}
int main(){
	freopen("E - Bob's Problem.in","r",stdin);
	freopen("E - Bob's Problem.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		long long ans=0;
		int n,m,k,cnt=0;
		memset(_ok,0,sizeof(_ok));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int u,v,w,c;
			scanf("%d%d%d%d",&u,&v,&w,&c);
			if(!c)fa[f(u)]=f(v),ans+=w;
			else e[++cnt]=(Edge){u,v,w};
		}
		sort(e+1,e+1+cnt,cmp);
		int kdl=0;
		for(int i=1;i<=cnt;i++){
			int a=e[i].u,b=e[i].v;
			if(f(a)==f(b))continue;
			else {
				kdl++;
				fa[f(a)]=f(b);
				ans+=e[i].w;
				_ok[i]=1;
			}
		}
		if(kdl>k)puts("-1");
		else {
			bool woc=0;
			for(int i=1;i<n;i++){
				if(f(i)!=f(i+1)){
					puts("-1");
					woc=1;
					break;
				}
			}
			if(woc)continue;
			for(int i=1;i<=cnt;i++){
				if(kdl==k)break;
				if(_ok[i])continue;
				ans+=e[i].w;kdl++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}


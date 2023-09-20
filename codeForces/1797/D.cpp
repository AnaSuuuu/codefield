#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,m,a[N],fa[N],pos[N];
ll id[N],head[N],tot;//id ��ǰ����ڵ�������λ�ã���ʾ�����Գ�ʼλ�ýڵ��ű�ʾ�� 
ll sum[N],son[N],ans[N];
set<tuple<ll,ll> >sons[N];
struct Edge{
	int _to,_next;
}e[N<<1];
void add_edge(int u,int v){
	tot++;
	e[tot]._to=v;
	e[tot]._next=head[u];
	head[u]=tot;
}
void dfs0(int u){
	sum[u]=1;
	int maxn=-1;
	for(int i=head[u];i;i=e[i]._next){
		int v=e[i]._to;
		if(!sum[v]){
			dfs0(v),fa[v]=u;
			sum[u]+=sum[v];
			sons[u].insert(make_tuple(-sum[v],v));
			if((sum[v]>maxn)||(sum[v]==maxn&&v<son[u]))maxn=sum[v],son[u]=v;
		}
	}
}
void dfs1(int u){
	ans[u]=a[id[u]];
	for(int i=head[u];i;i=e[i]._next){
		int v=e[i]._to;
		if(v==fa[u])continue;
		dfs1(v);
		ans[u]+=ans[v];
	}
	return ;
}
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),id[i]=i,pos[i]=i;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs0(1);
	dfs1(1);
	for(int i=1;i<=m;i++){
		int t,x;
		scanf("%d%d",&t,&x);
		switch(t){
			case 1:{
				printf("%lld\n",ans[x]);
				break;
			}
			case 2:{
				//cout<<son[x]<<endl;
				if(son[x]!=0){
					int f=fa[x],s=son[x];
					ans[x]-=ans[s];
					ans[s]+=ans[x];
					
					fa[s]=f;
					fa[x]=s;
					sons[x].erase(make_tuple(-sum[s],s));
					son[x]=sons[x].empty()?0:get<1>(*sons[x].begin());
          sum[x]-=sum[s];
					sum[s]+=sum[x];
					//int maxn=-1;sum[x]=1;son[x]=0;
					sons[s].insert(make_tuple(-sum[x],x));
					son[s]=get<1>(*sons[s].begin());
					sons[f].erase(make_tuple(-sum[s],x));
					sons[f].insert(make_tuple(-sum[s],s));
					son[f]=get<1>(*sons[f].begin());
					/*for(int j=head[x];j;j=e[j]._next){
						int v=e[j]._to;
						if(v==s||v==f)continue;
						if((sum[v]>maxn)||(sum[v]==maxn&&v<son[x]))maxn=sum[v],son[x]=v;
						sum[x]+=sum[v];
					}
					maxn=-1;sum[s]=1,son[s]=0;
					for(int j=head[s];j;j=e[j]._next){
						int v=e[j]._to;
						if((sum[v]>maxn)||(sum[v]==maxn&&v<son[s]))maxn=sum[v],son[s]=v;
						son[s]+=son[v];
					}/**/
				}
				break;
			}
		}
	}
	
	return 0;
}


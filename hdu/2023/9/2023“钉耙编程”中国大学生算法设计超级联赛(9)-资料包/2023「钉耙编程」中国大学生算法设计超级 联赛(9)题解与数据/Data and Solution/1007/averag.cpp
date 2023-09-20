#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pli pair<LL,int>
#define ppl pair<pli,LL>
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
const int mxn=1e6+10,mxm=1e3+10,infi=1e9,mod=1e9+7;
LL rd()
{
	static LL sl,fh,ch;
	sl=0;fh=1;ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int n,K,fa[mxn];
LL ansA,ansB,a[mxn];
int t,h[mxn];
struct Tre
{
	int to,nxt;
}e[mxn<<1];
vector<ppl> f[mxn];
void add(int u,int v)
{
	e[++t]=(Tre){v,h[u]};h[u]=t;
	e[++t]=(Tre){u,h[v]};h[v]=t;
}
LL my_gcd(LL a,LL b) {if(!a||!b) return a|b; for(LL c=a%b;c;a=b,b=c,c=a%b); return b;}
void chkans(LL A,LL B)
{
	if(1ll*ansA*B>=1ll*A*ansB) return ;
	ansA=A;ansB=B;
}
void dfs(int u)
{
	int v;f[u][0].fr=mp(a[u],u);
	for(int i=h[u];i;i=e[i].nxt)
		if((v=e[i].to)!=fa[u])
		{
			fa[v]=u;dfs(v);
			for(int j=0;j<K*2;++j)
				if(f[u][j].fr.fr)
					for(int k=0;j+k+2<K*2;++k)
						if(f[v][k].fr.fr&&j+k+2>=K)
							chkans(f[u][j].fr.fr+f[v][k].fr.fr,j+k+2);
			for(int j=1;j<K*2;++j)
				if(f[v][j-1].fr.fr)
				{
					LL val=f[v][j-1].fr.fr+a[u];
					if(val>f[u][j].fr.fr) f[u][j].sc=f[u][j].fr.fr,f[u][j].fr=mp(val,v);
					else if(val>f[u][j].sc) f[u][j].sc=val;
				}
		}
	for(int i=K;i<K*2;++i) chkans(f[u][i-1].fr.fr,i);
}
int main()
{
	for(int TT=rd();TT;--TT)
	{
		memset(h,0,sizeof(int)*(n+1));t=0;
		n=rd();K=rd();ansA=0;ansB=1;
		for(int i=1;i<=n;++i) a[i]=rd(),vector<ppl>(K*2,mp(mp(0,0),0)).swap(f[i]);
		for(int i=1;i<n;++i) add(rd(),rd());
		dfs(1);
		for(int v,x,Q=rd();Q;--Q)
		{
			v=rd();x=rd();a[v]+=x;
			for(int i=0;i<K*2;++i)
				if(f[v][i].fr.fr)
				{
					f[v][i].fr.fr+=x;
					if(f[v][i].sc) f[v][i].sc+=x;
				}
			for(int i=0;i<K*2;++i)
				if(f[v][i].fr.fr)
					for(int j=0;i+j+1<K*2;++j)
						if(i+j+1>=K)
						{
							if(f[v][j].fr.fr&&f[v][i].fr.sc!=f[v][j].fr.sc)
							{
								LL val=f[v][i].fr.fr+f[v][j].fr.fr-a[v];
								chkans(val,i+j+1);
							}
							else if(f[v][j].sc)
							{
								LL val=f[v][i].fr.fr+f[v][j].sc-a[v];
								chkans(val,i+j+1);
							}
						}
			for(int i=K;i<K*2;++i) chkans(f[v][i-1].fr.fr,i);
			for(int i=1,u=fa[v];u&&i<K*2;++i,v=u,u=fa[u])
			{
				for(int j=i;j<K*2;++j)
					if(f[v][j-1].fr.fr)
					{
						LL val=f[v][j-1].fr.fr+a[u];
						if(f[u][j].fr.sc==v) {f[u][j].fr.fr=val; continue;}
						if(val>f[u][j].fr.fr) f[u][j].sc=f[u][j].fr.fr,f[u][j].fr=mp(val,v);
						else if(val>f[u][j].sc) f[u][j].sc=val;
					}
				for(int j=0;j<K*2;++j)
					if(f[u][j].fr.fr)
						for(int k=0;j+k+1<K*2;++k)
							if(j+k+1>=K)
							{
								if(f[u][k].fr.fr&&f[u][j].fr.sc!=f[u][k].fr.sc)
								{
									LL val=f[u][j].fr.fr+f[u][k].fr.fr-a[u];
									chkans(val,j+k+1);
								}
								else if(f[u][k].sc)
								{
									LL val=f[u][j].fr.fr+f[u][k].sc-a[u];
									chkans(val,j+k+1);
								}
							}
				for(int j=K;j<K*2;++j) chkans(f[u][j-1].fr.fr,j);
			}
			LL G=my_gcd(ansA,ansB);
			printf("%lld/%lld\n",ansA/G,ansB/G);
		}
	}
	return 0;
}
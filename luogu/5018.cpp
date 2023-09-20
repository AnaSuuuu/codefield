#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int v[N],l[N],r[N],tmp;
bool dfs(int x,int y){
	int ok=1;
	tmp+=2;
	if(v[x]!=v[y])return 0;
	if((l[x]!=-1)&&(r[y]!=-1))ok=ok&dfs(l[x],r[y]);
	else if(l[x]!=-1||r[y]!=-1)return 0;
	if((r[x]!=-1)&&(l[y]!=-1))ok=ok&dfs(r[x],l[y]);
	else if(r[x]!=-1||l[y]!=-1)return 0;
	return ok;
}
int main(){
	freopen("5018.in","r",stdin);
	freopen("5018.out","w",stdout);
	int n,ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=n;i++){
		if((l[i]!=-1)&&(r[i]!=-1)&&(v[r[i]]==v[l[i]])){
			tmp=0;
			ans=max(ans,dfs(l[i],r[i])*(tmp+1));
		/*	tmp=0;
			cout<<i<<' '<<dfs(l[i],r[i])*(tmp+1)<<endl;*/
		}
	}
	/*tmp=0;
	cout<<dfs(7,8)<<endl;
	cout<<((l[7]!=-1)&&(r[7]!=-1)&&(v[r[7]]==v[l[7]]))<<endl;
	cout<<dfs(l[7],r[7])<<endl;
	cout<<tmp+1<<endl;*/
	cout<<ans<<endl;
	return 0;
}


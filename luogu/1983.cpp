#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int v[N],s[N][N];
int cnt[N],mm[N];
int M[N][N];
int main(){
	freopen("1983.in","r",stdin);
	freopen("1983.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&s[i][0]);
		memset(v,0,sizeof(v));
		for(int j=1;j<=s[i][0];j++)scanf("%d",&s[i][j]),v[s[i][j]]=1;
		for(int j=s[i][1];j<=s[i][s[i][0]];j++){
			if(!v[j])
				for(int k=1;k<=s[i][0];k++)if(!M[j][s[i][k]])M[j][s[i][k]]=1,cnt[s[i][k]]++;			
		}
	}
	int tmp,ans=0;
	do{
		tmp=0;
		vector<int> q;
		for(int i=1;i<=n;i++){
			if((cnt[i]==0)&&(mm[i]==0)){
				tmp++;
				mm[i]=1;
				q.push_back(i);
			}
		}
		while(q.size()){
			int tmp=q.back();
			q.pop_back();
			for(int i=1;i<=n;i++)if(M[tmp][i])cnt[i]--;
		}
		ans++;
	}while(tmp!=0);
	printf("%d\n",ans-1);
	return 0;
}


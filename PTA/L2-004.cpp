#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,ls[N],rs[N],a[N];
int maxn[N],minn[N],flag;
void dfs1(int root,int l,int r){
	int i;
	//cout<<a[root]<<' '<<l<<' '<<r<<endl;
	if(l>r)return ;
	for(i=l;i<=r;i++)
		if(a[i]>=a[root])break;
	//	cout<<i<<endl;
	if(i!=l){
		ls[root]=l;
		dfs1(l,l+1,i-1);
	}
	if(i<=r){
		rs[root]=i;
		dfs1(i,i+1,r);
	}
}
void dfs2(int root,int l,int r){
	int i;
	//cout<<a[root]<<' '<<l<<' '<<r<<endl;
	if(l>r)return ;
	for(i=l;i<=r;i++)
		if(a[i]<a[root])break;
	if(i!=l){
		ls[root]=l;
		dfs2(l,l+1,i-1);
	}
	if(i<=r){
		rs[root]=i;
		dfs2(i,i+1,r);
	}
}
void dfs3(int root){
	if(flag)return ;
	if(rs[ls[root]]){
		int x=rs[ls[root]];
		while(rs[x])x=rs[x];
		if(a[x]>=a[root]){
			flag=1;
			return ;
		}
	}
	if(ls[rs[root]]){
		int x=ls[rs[root]];
		while(ls[x])x=ls[x];
		if(a[x]<a[root]){
			flag=1;
			return ;
		}
	}
	if(ls[root])dfs3(ls[root]);
	if(rs[root])dfs3(rs[root]);
}
void dfs33(int root){
	if(flag)return ;
	if(rs[ls[root]]){
		int x=rs[ls[root]];
		while(rs[x])x=rs[x];
		if(a[x]<a[root]){
			flag=1;
			return ;
		}
	}
	if(ls[rs[root]]){
		int x=ls[rs[root]];
		while(ls[x])x=ls[x];
		if(a[x]>=a[root]){
			flag=1;
			return ;
		}
	}
	if(ls[root])dfs3(ls[root]);
	if(rs[root])dfs3(rs[root]);
}
void dfs4(int root){
	//cout<<a[root]<<endl;
	//cout<<root<<' '<<ls[root]<<endl;
	if(ls[root]){
		dfs4(ls[root]);
		//printf("%d ",a[ls[root]]);
	}
	if(rs[root]){
		dfs4(rs[root]);
		//printf("%d ",a[rs[root]]);
	}
	if(root==1)printf("%d",a[root]);
	else printf("%d ",a[root]);
}
int main(){
	freopen("L2-004.in","r",stdin);
	freopen("L2-004.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[2]<a[1]){
		dfs1(1,2,n);
		dfs3(1);
	}
	else {
		dfs2(1,2,n);
		dfs33(1);
	}
	/*for(int i=1;i<=n;i++)cout<<ls[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<rs[i]<<' ';
	cout<<endl;*/
	if(flag)puts("NO");
	else {
		puts("YES");
		dfs4(1);
	}/**/
	return 0;
}


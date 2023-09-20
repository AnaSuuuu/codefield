#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct Node{
	int pot,ext,id;
}s[N];
int a[N][N];
bool cmp(Node x,Node y){
	if(x.pot==y.pot)return x.ext>y.ext;
	else return x.pot>y.pot;
}
int main(){
	freopen("L - Who is the Champion.in","r",stdin);
	freopen("L - Who is the Champion.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		s[i].id=i;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			s[i].ext+=a[i][j];
			s[j].ext-=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(a[i][j]>a[j][i])s[i].pot+=3;
			//if(a[i][j]<a[j][i])s[j].pot+=3;
			if(a[i][j]==a[j][i])s[i].pot++;
		}
	}
	sort(s+1,s+1+n,cmp);
	if((s[1].pot==s[2].pot)&&(s[1].ext==s[2].ext))puts("play-offs");
	else printf("%d\n",s[1].id);
	return 0;
}


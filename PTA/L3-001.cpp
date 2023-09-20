#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m;
int a[N],tot;
int f[105],step[N][105];
void in(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=~f+1;
		c=getchar();
	}	
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	x*=f;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("L3-001.in","r",stdin);
	freopen("L3-001.out","w",stdout);
	in(n);in(m);
	for(register int i=1;i<=n;++i)in(a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i];j--)
			if(f[j]<=f[j-a[i]]+a[i]){
				f[j]=f[j-a[i]]+a[i];
				step[i][j]=1;
			}
	}
	if(f[m]==m){
		while(n){
			while(step[n][m]==0)n--;
			if(n>0){
				if(m-a[n])printf("%d ",a[n]);
				else printf("%d",a[n]);
				m-=a[n];
			}
			else break;
			if(m<=0)break;
			n--;
		}
	}
	else puts("No Solution");
	return 0;
}


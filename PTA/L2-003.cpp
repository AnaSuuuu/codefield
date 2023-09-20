#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct Node{
	double a,b;
}s[N];
bool cmp(Node x,Node y){
	return (double)x.b/x.a>(double)y.b/y.a;
}
int main(){
	freopen("L2-003.in","r",stdin);
	freopen("L2-003.out","w",stdout);
	int n;
	double d;
	scanf("%d%lf",&n,&d);
	for(int i=1;i<=n;++i){
		scanf("%lf",&s[i].a);
	}
	for(int i=1;i<=n;++i)scanf("%lf",&s[i].b);
	sort(s+1,s+1+n,cmp);
	double ans=0;
	for(int i=1;i<=n;i++){
		if(d>=s[i].a){
			d-=s[i].a;
			ans+=s[i].b;
		}
		else {
			ans+=(double)d*(double)s[i].b/s[i].a;
			d=0;
			break;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}


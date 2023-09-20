#include<cstdio>
using namespace std;
const int N=1e5+5;
int x[N],y[N];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==2){
		puts("No");
		return 0;
	}
	double tmp;
	scanf("%d%d%d%d",&x[1],&y[1],&x[2],&y[2]);
	tmp=(double)(1.0*y[1]-1.0*y[2])*1.0/(x[1]*1.0-x[2]*1.0); 
	for(int i=3;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(tmp!=((double)(1.0*y[i]-1.0*y[i-1])*1.0/(x[i]*1.0-x[i-1]*1.0))){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}

/*#include<cstdio>
using namespace std;
int main(){
	puts("Yes");
	return 0;
} */

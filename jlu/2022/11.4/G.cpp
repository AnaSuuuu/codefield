#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int gcd(int x,int y){
	if(y%x==0)return x;
	return gcd(y,x%y);
}
int main(){
	//freopen("G.in","r",stdin);
	//freopen("G.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x0,y0,x1,y1;
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		if(x0==x1){
			printf("%d %d\n",x0+1,y0);
			continue;
		}
		if(y0==y1){
			printf("%d\n",y0+1,x0);
			continue;
		}
		int X=abs(x0-x1),Y=abs(y0-y1);
		int g=gcd(X,Y);
		X/=g,Y/=g;
		double k=1.0*Y/X;
		int zh;
		if(k>0)zh=1;
		else zh=-1;
		Y*=zh;
		int x=min(x0,x1);
		int ansx,ansy;
		if(abs(k)>1)ansx=X+x0-1,ansy=y0+Y;
		else ansx=x0+X-1,ansy=y0;
		printf("%d %d\n",x,ansy);
	}
	return 0;
}
 

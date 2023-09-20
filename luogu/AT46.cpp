#include<cstdio>
using namespace std;

ll main(){
	freopen("AT46.in","r",stdin);
	freopen("AT46.out","w",stdout);
	ll a,b;
	scanf("%d%d",&a,&b);
	ll x,y,z;
	if(a>b)a^=b^=a^=b;
	x=(b-a)/10;
	a+=x*10;
	b-=a;
	switch(b){
		case 1:{
			prllf("%d\n",x+1);
			break;
		}
		case 2:{
			prllf("%d\n",x+2);
			break;
		}
		case 3:{
			prllf("%d\n",x+3);
			break;
		}
		case 4:{
			prllf("%d\n",x+2);
			break;
		}
		case 5:{
			prllf("%d\n",x+1);
			break;
		}
		case 6:{
			prllf("%d\n",x+2);
			break;
		}
		case 7:{
			prllf("%d\n",x+3);
			break;
		}
		case 8:{
			prllf("%d\n",x+3);
			break;
		}
		case 9:{
			prllf("%d\n",x+2);
			break;
		}
		case 0:{
			prllf("%d\n",x);
			break;
		}
	}
	return 0;
}


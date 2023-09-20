#include<cstdio>
#include<ctime>
using namespace std;
int main(){
	//srand(time(NULL));
	freopen("D.in","w",stdout);
	printf("10\n");
	for(int i=1;i<=10;i++)printf("%d ",i*i*i*i%10);
	puts("");
	for(int i=1;i<=10;i++)printf("%d ",i*i*i%10);
	
	return 0;
}


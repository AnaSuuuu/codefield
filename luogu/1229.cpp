#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char a[N],b[N];
int main(){
	freopen("1229.in","r",stdin);
	freopen("1229.out","w",stdout);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int len=strlen(a+1),ans=1;
	for(int i=1;i<len;i++)
		for(int j=2;j<=len;j++)
			if(a[i]==b[j]&&a[i+1]==b[j-1])ans<<=1;
	printf("%d\n",ans);
	return 0;
}


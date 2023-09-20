#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int lower[N],cal[N];
int num[N];//num[i]表示i在lower数组中要找第num[i]个 ,即lower[num[i]]>=i 
int main(){
	freopen("D.in","r",stdin);
	freopen("D0.out","w",stdout);
	int n;
	int tmp=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	b[0]=n+1;
	for(int i=1;i<=n;i++){
		//printf("%d ",b[i]);
		//cout<<b[i]<<' '<<b[i-1]<<endl;
		if(b[i]!=b[i-1]){
			lower[++tmp]=b[i];
			num[b[i]]=tmp; 
		}
		cal[b[i]]++;
	}
	int qwq=1;
	for(int i=0;i<=lower[tmp];i++){
		if(lower[qwq]<i)qwq++;
		num[i]=qwq;
	}
	//cout<<tmp<<endl;
	for(int i=lower[tmp]+1;i<n;i++)num[i]=1;
//	for(int i=1;i<=tmp;i++)cout<<lower[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++)cout<<num[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=n;i++){
		int kdl=n-a[i];
	//	cout<<kdl<<endl;
		if(cal[kdl]){
			cal[kdl]--;
			printf("%d ",(kdl+a[i])%n);
		}
		else{
			int j;
			for(j=num[kdl];j<=tmp;j++){
				if(cal[lower[j]]){
					cal[lower[j]]--;
					printf("%d ",(lower[j]+a[i])%n);
					break;
				}
			}
			if(j>tmp){
				for(j=1;j<num[kdl];j++){
					if(cal[lower[j]]){
						cal[lower[j]]--;
						printf("%d ",(lower[j]+a[i])%n);
						break;
					}
				}
			}
		}
	}
	return 0;
}


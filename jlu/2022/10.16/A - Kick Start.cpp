#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct Date{
	int mon,da;
}d[N];
bool cmp(Date x,Date y){
	return x.mon==y.mon?x.da<y.da:x.mon<y.mon;
}
const char zh[15][5]={{"Jan"},{"Feb"},{"Mar"},{"Apr"},{"May"},{"Jun"},{"Jul"},{"Aug"},{"Sept"},{"Oct"},{"Nov"},{"Dec"}};
void work(int i){
	printf("%s %d",zh[d[i].mon-1],d[i].da);
	if(d[i].da>=11&&d[i].da<=13){
		puts("th");
		return ;
	}
	if((d[i].da%10<1)||(d[i].da%10>3))puts("th");
	else switch(d[i].da%10){
		case 1:{
			puts("st");
			break;
		}
		case 2:{
			puts("nd");
			break;
		}
		case 3:{
			puts("rd");
			break;
		}
	}
}
int main(){
	freopen("A - Kick Start.in","r",stdin);
	freopen("A - Kick Start.out","w",stdout);
	int t,id=0;
	scanf("%d",&t);
	while(t--){
		int n;
		printf("Case #%d: ",++id);
		scanf("%d\n",&n);
		for(int i=1;i<=n;i++){
			char a[15],b[15];
			scanf("%s %s\n",a+1,b+1);
			if((a[1]=='J')&&(a[2]=='a'))d[i].mon=1;
			if((a[1]=='F')&&(a[2]=='e'))d[i].mon=2;
			if((a[1]=='M')&&(a[2]=='a')&&(a[3]=='r'))d[i].mon=3;
			if((a[1]=='A')&&(a[2]=='p'))d[i].mon=4;
			if((a[1]=='M')&&(a[2]=='a'&&(a[3]=='y')))d[i].mon=5;
			if((a[1]=='J')&&(a[2]=='u')&&(a[3]=='n'))d[i].mon=6;
			if((a[1]=='J')&&(a[2]=='u')&&(a[3]=='l'))d[i].mon=7;
			if((a[1]=='A')&&(a[2]=='u'))d[i].mon=8;
			if((a[1]=='S')&&(a[2]=='e'))d[i].mon=9;
			if((a[1]=='O')&&(a[2]=='c'))d[i].mon=10;
			if((a[1]=='N')&&(a[2]=='o'))d[i].mon=11;
			if((a[1]=='D')&&(a[2]=='e'))d[i].mon=12;
			if(strlen(b+1)==4)d[i].da=(b[1]-'0')*10+(b[2]-'0');
			else d[i].da=b[1]-'0';
		}
		char a[15],b[15];
		int mon,da;
		scanf("%s %s\n",a+1,b+1); 
		if((a[1]=='J')&&(a[2]=='a'))mon=1;
		if((a[1]=='F')&&(a[2]=='e'))mon=2;
		if((a[1]=='M')&&(a[2]=='a')&&(a[3]=='r'))mon=3;
		if((a[1]=='A')&&(a[2]=='p'))mon=4;
		if((a[1]=='M')&&(a[2]=='a'&&(a[3]=='y')))mon=5;
		if((a[1]=='J')&&(a[2]=='u')&&(a[3]=='n'))mon=6;
		if((a[1]=='J')&&(a[2]=='u')&&(a[3]=='l'))mon=7;
		if((a[1]=='A')&&(a[2]=='u'))mon=8;
		if((a[1]=='S')&&(a[2]=='e'))mon=9;
		if((a[1]=='O')&&(a[2]=='c'))mon=10;
		if((a[1]=='N')&&(a[2]=='o'))mon=11;
		if((a[1]=='D')&&(a[2]=='e'))mon=12;
		if(strlen(b+1)==4)da=(b[1]-'0')*10+(b[2]-'0');
		else da=b[1]-'0';
		sort(d+1,d+1+n,cmp);
		bool _ok=1;
		/*for(int i=1;i<=n;i++){
			cout<<d[i].mon<<' '<<d[i].da<<endl;
		}
		cout<<mon<<' '<<da<<endl;*/
		for(int i=1;i<=n;i++){
			if((d[i].mon>mon)||((d[i].mon==mon)&&(d[i].da>da))){
			//	cout<<i<<endl;
				work(i);
				_ok=0;
				break;
			}
		}
		if(_ok)puts("See you next year");
	} 
	return 0;
}


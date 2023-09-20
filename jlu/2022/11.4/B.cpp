#include<bits/stdc++.h>
using namespace std;
struct Node{
  int t,m,id;
  int sta;
}s[405][10];//测试点数据
char c[5];
int q[105],q0[105];
bool judge(int lim){
	
}
int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int n,m,ans;
  scanf("%d%d",&n,&m);
  //for(int i=1;i<=n;i++)s[i][0].id=i;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      char c,d;
      scanf("\n%c%c,%d/%d ",&c,&d,&s[i][j].t,&s[i][j].m);
      if(c=='O')s[i][j].sta=0;
      if(c=='W')s[i][j].sta=1;
      if(c=='T')s[i][j].sta=2;
      if(c=='M')s[i][j].sta=3;
      if(c=='R')s[i][j].sta=4;
    }
  }
  int tot=0,tot0=1;
  for(int i=1;i<=m;i++){
    int maxt=0,maxm=0,sta=0;
    for(int j=1;j<=n;j++){
      maxt=max(maxt,s[j][i].t);
      maxm=max(maxm,s[j][i].m);
      if(s[j][i].sta!=0){
        sta=s[j][i].sta;
        break;
      }
    }
   // cout<<maxt<<' '<<maxm<<' '<<sta<<endl;
    for(int j=1;j<=n;j++){
      if(s[j][i].m==maxm&&s[j][i].t<=maxt)q[++tot]=j;
      else{
      	if(s[j][i].t==maxt&&s[j][i].m<=maxm)q[++tot]=j;
      	else if(s[j][i].sta==sta&&s[j][i].t<=maxt&&s[j][i].m<=maxm&&sta)q[++tot]=j;
	  }
    }
    //cout<<tot<<endl; 
  }
  sort(q+1,q+1+tot);
  q0[1]=q[1];
  for(int i=2;i<=tot;i++){
    if(q[i]!=q[i-1])q0[++tot0]=q[i];
  }
  //for(int i=1;i<=tot0;i++)cout<<q0[i]<<' ';
  int l=1,r=tot0;
  while(l<=r){
  	int mid=(l+r)>>1;
  	if(judge(mid)){
  		r=mid-1;
  		ans=mid;
	}
	else l=mid+1;
  }
  printf("%d\n",ans);
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool judge(int x,int y){
  int tmp=y;
  while(tmp<x)tmp*=y;
  if(tmp==x)return true;
  tmp/=y;
  while(x&&tmp>=1){
    if(x>=tmp)x-=tmp;
    tmp/=y;
  }
  if(x)return false;
  return true;
}
int main(){
  freopen("F.in","r",stdin);
  freopen("F.out","w",stdout);
  int t;
  cin>>t;
  while(t--){
    int n,ans=2;
    scanf("%d",&n);
    if(n==2){
      puts("1");
      continue;
    }
    if(n==3){
      puts("2");
      continue;
    }
    for(int i=2;;i++){
      double x=pow(n,1.0/i);
      int c=(int)x;
      if(c==1)break;
      if(judge(n,c))ans++;
    }
    printf("%d\n",ans);
  }
  return 0;
}